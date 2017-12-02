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

char ** parse_args(char * line){
  char ** s1 = (char **)malloc(sizeof(line));

  int i = 0;
  char * pos;

  while(line){
    s1[i] = strsep(&line, " ");
    if ((pos=strchr(s1[i], '\n')) != NULL) {
      *pos = '\0';
    }
    i++;
  }

  return s1;
}

int main(){
  printf("---LiLee shell initiated!---\n");

  //reading in stdin and parsing
  char line[100];
  fgets(line, 100, stdin);
  printf("line is: %s\n", line);
  char ** args = parse_args(line);

  int f;
  f = fork();

  if (f == 0) {
      //child process
      printf("Child is running!\n");

      //don't do it if its exit or cd
      if(!strcmp(args[0], "exit") || !strcmp(args[0], "cd")) {
        exit (0);
      }

      //exec
      execvp(args[0], args);
  }

  else {
    int status;
    wait(&status);
    printf("Parent is running!\n");

    if(!strcmp(args[0], "exit")){
      exit(0);
    }
    if(!strcmp(args[0], "cd")) {
      int works;
      works = chdir(args[1]);
      printf("runs? %d\n", works);
    }
    printf("Parent Done!\n");
  }
  //printf("error: %s\n", strerror(errno));
  return 0;
}
