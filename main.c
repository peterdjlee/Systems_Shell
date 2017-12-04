#include "header.h"

int main(){
  printf("\nWelcome to Li-Lee shell. Waiting for you to type...\n");
  printf("Note: You MUST NOT use whitespace when using ';'\n");
  printf("Type 'exit' to exit.\n");
  printf("Type 'magic' to hide/show your current working directory.\n\n");

  int cwd_on = 1;
  while (1) {
    if (cwd_on) {
      char cwd[1024];
      if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s$ ", cwd);
      }
    } else {
      printf("Li-Lee$ ");
    }

    char line[100];
    fgets(line, 100, stdin);
    char ** args = parse_args(line, ';');

    if(!strcmp(line, "magic")) {
      if (cwd_on == 0) {
        cwd_on = 1;
      } else {
        cwd_on = 0;
      }
      continue;
    }

    int i = 0;
    int status;
    while (args[i]) {
      char ** cmd = parse_args(args[i], ' ');
      exec_one(cmd);
      wait(&status);
      if(!strcmp(cmd[0], "exit")){
        printf("Quitting...\n");
        exit(0);
      }
      if(!strcmp(cmd[0], "cd")) {
        if (chdir(cmd[1]) == -1) {
          printf("-bash: cd: %s: %s\n", cmd[1], strerror(errno));
        }
      }
      i++;
    }
  }
  return 0;
}
