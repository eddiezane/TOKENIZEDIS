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

  char *c = malloc(2);

  //shouldn't change....
  tk -> full = strdup(ts);

  //changes with tkgetnexttoken
  tk -> curr = tk -> full;

  //shouldn't change after this function
  tk -> delims = malloc(200);

  for (; *separators != '\0'; separators++) {
    if (*separators == '\\') {
      if (handleSpec(c, separators))
        separators++;
    }

    else {
      //copy current char to c
      strncpy(c, separators, 1);
    }

    //copy c to tk->delims
    strncat(tk->delims, c, 1);
  }

  free(c);
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
  char *buff = malloc(200);
  char *c = malloc(2);

  while (strlen(buff) < 200) {

    /* Are we at the end of the string */
    if (*(tk->curr) == '\0') {
      if (strlen(buff) == 0) {
        free(buff);
        return 0;
      }
      return buff;
    }

    /* Is this an escape character */
    else if (*tk->curr == '\\') {
      if (handleSpec(c, tk->curr))
        tk->curr++;
    }

    /* Is current char a delim? */
    else if (isDelim(*(tk->curr), tk->delims)) {
      tk->curr++;
      break;
    }

    /* It must be a normal character */
    else {
      strncpy(c, tk->curr, 1);
    }

    strncat(buff, c, 1);
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
  int i;
  char *t;

  if (argc != 3) {
    printHelp();
    exit(1);
  }

  tok = TKCreate(argv[1], argv[2]);

  while ((t  = TKGetNextToken(tok))) {
    for(i = 0; i < strlen(t); i++) {
      if (isSpec(t[i])) 
        printf("[0x%.2x]", t[i]);
      else 
        printf("%c", t[i]);
    }
    printf("\n");
  }

  TKDestroy(tok);

  return 0;
}
