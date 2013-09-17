#include <stdio.h>
#include <string.h>

void printHelp() {
  printf("HALP !!\n");
}

char handleSpec(char *s) {
  switch (*(s+1)) {
    case 'n':
      break;

    case 't':
      break;

    case 'v':
      break;

    case 'b':
      break;

    case 'r':
      break;

    case 'f':
      break;

    case 'a':
      break;

    case '\\':
      break;

    case '\?':
      break;

    case '\'':
      break;

    case '\"':
      break;

    case '0':
      break;

    case 'x':
      break;

    default:
      break;
  }
  return '\0';
}

int isDelim(char c, char *delims) {
  int i;

  for (i = 0; i < strlen(delims); i++) {
    if (c == delims[i])
      return 1;
  }
  return 0;
}
