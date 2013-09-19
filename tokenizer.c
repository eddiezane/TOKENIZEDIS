/*
 * tokenizer.c
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "utils.h"

/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */

struct TokenizerT_ {
  char *bv;
  char *fullString;
  char *current;
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
  char *tmp;
  int i;

  TokenizerT *tok = malloc(sizeof(TokenizerT));

  tok->fullString = formatString(ts);
  tok->current = tok->fullString;

  tmp = formatString(separators);
  
  tok->bv = calloc(128, 1);
  for (i = 0; i < strlen(tmp); i++) 
    tok->bv[(int)tmp[i]] = 1;

  return tok;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy(TokenizerT *tok) {
  free(tok->fullString);
  free(tok->bv);
  free(tok);
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

char *TKGetNextToken(TokenizerT *tok) {
  int i;
  char *nextTok = calloc(200, 1);

  for (i = 0; strlen(tok->current); i++) {
    /* is a delim */
    if (tok->bv[(int)tok->current[i]]) {
      tok->current = &tok->current[i + 1];
      /* tok->current += i + 1; */ //TODO TRY LATER
      break;
    }
    nextTok[i] = tok->current[i];
  }
  return nextTok;
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
  char *w;

  if (argc != 3) {
    printHelp();//TODO
  }

  tok = TKCreate(argv[1], argv[2]);

  while (w = TKGetNextToken != NULL){
    printWord(w);//TODO
  }


  return 0;
}
