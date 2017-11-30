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

char ** parse_args(char * line);

int main(){
  printf("LiLee shell initiated\n");
  char line[100];
  fgets(line, 100, stdin);
  printf("line is: %s\n", line);
  char ** args = parse_args(line);
  pid_t pid = fork();
  if (!pid) {
     execvp(args[0], args);
  } else {
    
  }
  printf("error: %s\n", strerror(errno));
  return 0;
}

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
