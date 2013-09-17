/*
 * tokenizer.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */

struct TokenizerT_ {
  char *full;
  char *curr;
  char *delims;
};

typedef struct TokenizerT_ TokenizerT;

/*
 * TKCreate creates a new TokenizerT object for a given set of separator
 * characters (given as a string) and a token stream (given as a string).
 * 
 * TKCreate should copy the two arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

TokenizerT *TKCreate(char *separators, char *ts) {
  TokenizerT *tk = malloc(sizeof(TokenizerT));

  tk -> full = strdup(ts);
  tk -> curr = tk -> full;
  tk -> delims = strdup(separators);

  return tk;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy(TokenizerT *tk) {
  free(tk->full);
  free(tk->delims);
  free(tk);
}

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

char *TKGetNextToken(TokenizerT *tk) {
  int i;
  char *buff;

  buff = malloc(200);

  for (i = 0; i < 200; i++) {

    /* Are we at the end of the string */
    if (*tk->curr == '\0') {
      return buff;
    }

    /* Is this an escape character */
    else if (*tk->curr == '\\') {
      handleSpec(tk->curr);
      //TODO
    }

    /* Is current char a delim? */
    else if (isDelim(*(tk->curr), tk->delims)) {
      tk->curr++;
      break;
    }

    /* It must be a normal character */
    else {
      strncat(buff, tk->curr, 1);
    }
    tk->curr++;
  }

  if (strcmp(buff, "") == 0) {
    free(buff);
    return TKGetNextToken(tk);
  }
  return buff;
}


char *TKGetNextToken2(TokenizerT *tk) {
  char *buff;

  buff = calloc(200, 0);

  for (; tk->curr != '\0'; tk->curr++) {

    /* Is this an escape character */
    if (*tk->curr == '\\') {
      handleSpec(tk->curr);
      //TODO
    }

    /* Is current char a delim? */
    if (isDelim(*(tk->curr), tk->delims)) {
      tk->curr++;
      break;
    }

    /* It must be a normal character */
    else {
      strncat(buff, tk->curr, 1);
    }
    tk->curr++;
  }

  if (strcmp(buff, "") == 0) {
    free(buff);
    return TKGetNextToken(tk);
  }
  return buff;
}

/*
 * main will have two string arguments (in argv[1] and argv[2]).
 * The first string contains the separator characters.
 * The second string contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

int main(int argc, char **argv) {
  TokenizerT *tok;
  char *t;

  if (argc != 3) {
    printHelp();
    exit(1);
  }

  tok = TKCreate(argv[1], argv[2]);

  while (strcmp(t = TKGetNextToken(tok), "") != 0) {
    printf("%s\n", t);
  }

  TKDestroy(tok);

  return 0;
}
