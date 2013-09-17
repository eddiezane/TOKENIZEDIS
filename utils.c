#include <stdio.h>
#include <string.h>

void printHelp() {
  printf("HALP !!\n");
}

int handleSpec(char *c, char *s) {
  switch (*(s+1)) {
    case 'n':
      strcpy(c, "\n");
      return 1;

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

/* is c a delim */
int isDelim(char c, char *delims) {

  while (*delims != '\0') {
    if (c == *delims)
      return 1;
    delims++;
  }
  return 0;
}
