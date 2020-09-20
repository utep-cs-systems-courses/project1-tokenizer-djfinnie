#include "tokenizer.h"
#include <stdlib.h>
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
}



/* Returns a pointer to the first character of the next 

   space-separated word in zero-terminated str.  Return a zero pointer if 

   str does not contain any words. */
char *word_start(char *str)
{
  int i;
  char *p = str;
  
  for (i = 0; *(p+i) != '\0'; i++)
    {
      if (non_space_char(*(p+i))) return p+i;
    }
  return p+i;
}

/* Returns a pointer terminator char following *word */

char *word_terminator(char *word)
{
  int i;
  char *p = word;

  for (i = 0; *(p+i) != '\0'; i++)
    {
      if (space_char(*(p+i))) return p+i;
    }
  return p+i;
}

/* Counts the number of words in the string argument. */

int count_words(char *str)
{
  int num_words = 0;
  char *p = word_start(str);

  while (*p != '\0')
    {
    if (non_space_char(*p)) num_words += 1;
    
    p = word_terminator(p);
    p = word_start(p); 
    }
  return num_words;
}
	  



 /* Returns a fresly allocated new zero-terminated string 

    containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len)
{
  int i;
  char *copy = malloc((len+1) * sizeof(char));

  for (i = 0; i < len; i++)
    {
      copy[i] = inStr[i]; 
    }
  
  copy[i] = '\0';
  return copy;
}

 /* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

 */

char **tokenize(char* str)
{
  char *p = str;
  int num_words = count_words(str);
  char **tokens = malloc((num_words+1) * sizeof(char *));
  int i;

  for (i = 0; i < num_words; i++)
    {
      p = word_start(p); 
      char *start = p;
      char *end = word_terminator(start);
      int length = start -end;
      
      tokens[i] = copy_str(p, length); 

      p = word_terminator(p); 
    }
  
  tokens[i] = 0; 
  return tokens;
}



 /* Prints all tokens. */

 void print_tokens(char **tokens)
 {
   for (int i = 0; tokens[i] != 0; i++) {

     printf("%s ",tokens[i]);
   }
 }



 /* Frees all tokens and the vector containing themx. */

 void free_tokens(char **tokens)
 {
   
 }
