#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

char ** parse_args(char * line, char delimiter){
  int size = 6;
  char ** s1 = (char **)malloc(size * sizeof(char *));

  int i = 0;
  char * pos;

  while(line){
    s1[i] = strsep(&line, &delimiter);
    // If newline is there make it null
    if ((pos=strchr(s1[i], '\n')) != NULL) {
      *pos = '\0';
    }
    i++;
  }
  // s1[i - 1] = 0;
  s1[i] = 0;
  return s1;
}

void exec_one(char ** args) {
  int f = fork();
  if (f == 0) {
    //child process
    //printf("Child is running!\n");

    //don't do it if its exit or cd
    if(!strcmp(args[0], "exit") || !strcmp(args[0], "cd")) {
      //printf("CHILD FINISHED\n");
      exit(0);
    }
    int i = 0;
    i = execvp(args[0], args);
    // printf("I just execed");
    // printf("execvp result: %d\n", i);
    // printf("error: %s\n", strerror(errno));
    //printf("CHILD FINISHED\n");
    exit(0);
  }
}

int main(){
  printf("~~~~~~~~~~LI-LEE SHELL~~~~~~~~~~\n");
  printf("Note: You MUST NOT use whitespace when using ;\n");
  printf("Type 'exit' to exit.\n");
  while (1) {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    //fprintf(stdout, "Current working dir: %s\n", cwd);
    printf("%s$ ", cwd);
    //reading in stdin and parsing
    char line[100];
    fgets(line, 100, stdin);
    //printf("line is: %s\n", line);
    char ** args = parse_args(line, ';');

    int i = 0;
    int status;
    while (args[i]) {
      // printf("Starting %d cmd\n", i);
      char ** cmd = parse_args(args[i], ' ');
      exec_one(cmd);
      //printf("-----Parent is running for %d!-----\n", i);
      wait(&status);
      if(!strcmp(cmd[0], "exit")){
        printf("Quitting...\n");
        exit(0);
      }
      if(!strcmp(cmd[0], "cd")) {
        int works;
        works = chdir(cmd[1]);
        //printf("runs? %d\n", works);
      }
      // printf("I just execed my %dth cmd\n", i);
      i++;
    }

    //printf("-----Parent Done!-----\n");
  }
  //printf("error: %s\n", strerror(errno));
  return 0;
}
