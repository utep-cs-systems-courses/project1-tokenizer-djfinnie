#include "tokenizer.h"
#include <string.h>
#include <stdio.h>




/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c)
{
  if (c < '!') return 1;
  else return 0;
}


/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c)
{
  if (c >= '!') return 1;
  return 0;



/* Returns a pointer to the first character of the next 

   space-separated word in zero-terminated str.  Return a zero pointer if 

   str does not contain any words. */

char word_start(char *str); 
