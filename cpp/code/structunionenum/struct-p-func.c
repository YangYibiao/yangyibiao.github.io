#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cmd_i(char *s);
int cmd_q(char *s);
int cmd_c(char *s);

struct {
  char *name;
  char *des;
  int (*handler)(char *);
} cmd_table[] = {
    {"i", "Print info", cmd_i},
    {"q", "Exit",       cmd_q},
    {"c", "Continue",   cmd_c}
};

#define CMD_LEN sizeof(cmd_table)/sizeof(cmd_table[0])

int main() {
  while (1) {
    char *cmdline = malloc(20);
    scanf("%[^\n]", cmdline);
    printf("cmdline: %s\n", cmdline);
    scanf("%*c");

    char *arg = strtok(cmdline, " ");
    bool cmd_valid = false;

    for (int i = 0; i < CMD_LEN; i++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        char *remaining = arg + strlen(arg) + 1;
        printf("remaining: %s\n", remaining);
        cmd_table[i].handler(remaining);
        cmd_valid = true;
        break;
      }
    }
    if (!cmd_valid)
      printf("Cmd %s not supported\n", arg);
    free(cmdline);
  }
}

int cmd_i(char *s) {
  printf("In cmd_i, printing info!\n");
  printf("Info: %s\n", s);
  return 0;
}

int cmd_q(char *s) {
  printf("In cmd_q, exit!\n");
  exit(EXIT_SUCCESS);
}

int cmd_c(char *s) {
  printf("In cmd_c, continue!\n");
  return 0;
}