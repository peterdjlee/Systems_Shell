#include "header.h"

/*
  char ** parse_args(char * line, char delimiter)
  Description:
    Parses the given string using the given delimiter
  Arguments:
    char * line -> A pointer to the original string
    char delimiter -> The character that is going to be used to parse the string
  Return Value:
    A char ** which consists of the parsed strings
*/
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
  s1[i] = 0;
  return s1;
}

/*
  void exec_one(char ** args)
  Description:
    Forks off and the child process
  Arguments:
    char * line -> A pointer to the original string
    char delimiter -> The character that is going to be used to parse the string
  Return Value:
    A char ** which consists of the parsed strings
*/
void exec_one(char ** args) {
  int f = fork();
  if (f == 0) {
    // Child process

    // Exit if the command is exit or cd
    if(!strcmp(args[0], "exit") || !strcmp(args[0], "cd")) {
      exit(0);
    }
    int i = 0;
    i = execvp(args[0], args);
    if (i < 0) {
      printf("-bash: %s: %s \n", args[0], strerror(errno));
    }
    exit(0);
  }
}
