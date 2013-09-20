/*
 * utils.c 
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

char *formatString(char *s) {
  int i;
  char *ret, *p, c;

  ret = calloc(200, 1);
  p = ret;


  for (i = 0; i < strlen(s); i++, p++) {
    if (s[i] == '\\' && i < strlen(s)) {
      if ((c = handleSpec(s[i+1]))) {
        *p = c;
        i++;
      } else {
        *p = '\\';
      }
    } else {
      *p = s[i];
    }
  }
  return ret;
}

void printHelp() {
  printf("HELP\n");
}

void printWord(char *w) {
  int i;

  for (i = 0; i < strlen(w); i++) {
    if (isSpec(w[i]))
      printf("[0x%.2x]", w[i]);
    else
      printf("%c", w[i]);  
  }
  printf("\n");
}

char handleSpec(char spec) {
  switch (spec) {
    case 'n':
      return '\n';

    case 't':
      return '\t';

    case 'v':
      return '\v';

    case 'b':
      return '\b';

    case 'r':
      return '\r';

    case 'f':
      return '\f';

    case 'a':
      return '\a';

    case '\\':
      return '\\';

    case '\?':
      return '\?';

    case '\'':
      return '\'';

    case '\"':
      return '\"';

    default:
      return '\0';
  }
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
