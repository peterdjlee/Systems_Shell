#include "header.h"

int main(){
  printf("\nWelcome to Li-Lee shell. Waiting for you to type...\n");
  printf("Note: You MUST NOT use whitespace when using ';'\n");
  printf("Note: Type 'exit' to exit.\n");
  printf("Note: Type 'magic' to hide/show your current working directory.\n\n");
  int cwd_on = 1;

  while (1) {
    // All for the magic
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

    // All for the magic
    if(!strcmp(line, "magic")) {
      if (cwd_on == 0) {
        cwd_on = 1;
      } else {
        cwd_on = 0;
      }
      continue;
    }

    if(!strcmp(line, "exit")) {
      printf("Aw... leaving already?\n\n");
      printf("Bye!\n\n");
      exit(0);
    }

    int i = 0;
    int status;
    // Parse each set of commands and execute
    while (args[i]) {
      char ** cmd = parse_args(args[i], ' ');
      // If directory for cd doesn't exist, print error
      if(!strcmp(cmd[0], "cd")) {
        if (chdir(cmd[1]) == -1 && cmd[1] != NULL) {
          printf("-bash: cd: %s: %s\n", cmd[1], strerror(errno));
        }
      }
      exec_one(cmd);
      // Be a good parent and wait for child
      wait(&status);
      i++;
    }
  }
  return 0;
}
