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
  // char line[100] = "ls -a -l";
  // char ** args = parse_args(line);
  // execvp(args[0], args);

  FILE *f1 = fopen("test.txt", "r");
  int i;
  fseek(f1, 0, SEEK_END);
  int inputsize = ftell(f1); //its about text's size
  char input1[inputsize];
  fseek(f1,0,SEEK_SET);
  printf("%d\n", inputsize);
  for(i = 0; i < inputsize; i++) {
    fscanf(f1, "%c", &input1[i]);
    printf("%c", input1[i]);
  }

  printf("%c", input1[5]);
  return 0;
}

char ** parse_args(char * line){
  char ** s1 = (char **)calloc(6, sizeof(line));

  int i = 0;
  while(line){
    s1[i] = strsep(&line, " ");
    i++;
  }

  int x;
  for(x = 0; x < 6; x++){
    printf("arguments: %s\n", s1[x]);
  }

  return s1;
}
