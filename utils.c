/*
 * utils.c 
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *formatString(char *s) {
  int i;
  char *ret, *p;

  ret = calloc(200, 1);
  p = ret;


  for (i = 0; i < strlen(s); i++) {
    if (s[i] == '\\') {

    } else {
      *ret = s[i];
      p++;
    }

  }


  return NULL;
}

void printHelp() {
  printf("HELP\n");
}

void printWord(char *w) {
}
