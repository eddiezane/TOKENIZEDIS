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
      strcpy(c, "\t");
      return 1;
      break;

    case 'v':
      strcpy(c, "\v");
      return 1;
      break;

    case 'b':
      strcpy(c, "\b");
      return 1;
      break;

    case 'r':
      strcpy(c, "\r");
      return 1;
      break;

    case 'f':
      strcpy(c, "\f");
      return 1;
      break;

    case 'a':
      strcpy(c, "\a");
      return 1;
      break;

    case '\\':
      strcpy(c, "\\");
      return 1;
      break;

    case '\?':
      strcpy(c, "\?");
      return 1;
      break; 

    case '\'':
      strcpy(c, "\'");
      return 1;
      break;

    case '\"':
      strcpy(c, "\"");
      return 1;
      break;

    default:
      break;
  }
  return 0;
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
