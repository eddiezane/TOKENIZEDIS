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

    case 'v':
      strcpy(c, "\v");
      return 1;

    case 'b':
      strcpy(c, "\b");
      return 1;

    case 'r':
      strcpy(c, "\r");
      return 1;

    case 'f':
      strcpy(c, "\f");
      return 1;

    case 'a':
      strcpy(c, "\a");
      return 1;

    case '\\':
      strcpy(c, "\\");
      return 1;

    case '\?':
      strcpy(c, "\?");
      return 1;

    case '\'':
      strcpy(c, "\'");
      return 1;

    case '\"':
      strcpy(c, "\"");
      return 1;
    
    default:
      break;
  }
  return 0;
}

int isSpec(char c) {
  if(c == '\n')
    return 1;
  if (c == '\t')
    return 1;
  if (c == '\v')
    return 1;
  if (c == '\b')
    return 1;
  if (c == '\r')
    return 1;
  if (c == '\f')
    return 1;
  if (c == '\a')
    return 1;
  if (c == '\\')
    return 1;
  if (c == '\?')
    return 1;
  if (c == '\'')
    return 1;
  if (c == '\"')
    return 1;
  else
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
