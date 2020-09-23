#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>




/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c)
{
  if (c < '!' && c != 0) return 1;  // All whitespace character values are less than '!'
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
      if (non_space_char(*(p+i))) return p+i; // Return pointer of first found character
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
      if (space_char(*(p+i))) return p+i;  // Return pointer of first space character found
    }
  return p+i;
}

/* Counts the number of words in the string argument. */

int count_words(char *str)
{
  int num_words = 0;
  char *p = word_start(str);
  int i;
  
  for (i = 0; *(str +i) != '\0'; i++)
    {
      if (non_space_char(*(str+i))) num_words += 1;  // Add one to num_words if a letter is read
    
      p = word_terminator(p);  // Skip to end of the word
      p = word_start(p);       // Skip to next word     
    }
      

  return num_words;
}
	  



 /* Returns a fresly allocated new zero-terminated string 

    containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len)
{
  int i;
  char *copy = malloc((len+1) * sizeof(char));  // Allocate memory for new string of chars

  for (i = 0; i < len; i++)
    {
      copy[i] = inStr[i];   // Fill new char pointer addresses with inStr chars 
    }
  
  copy[i] = '\0';           // Make last char the terminating variable
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
  
  // Use number of words and size of char * to store tokenized word 
  char **tokens = malloc((num_words+1) * sizeof(char *)); 
  int i;

  for (i = 0; i < num_words; i++)
    {
      p = word_start(p);               // Go to word start
      int j;
      int length= 0;
      for (j = 0; *(p+j) != '\0'; j++) // Get the lenght of the current word
	{
	  length++;
	}
      
      tokens[i] = copy_str(p, length); // Copy string into token array 

      p = word_terminator(p);          // Go to end of word
    }
  
  tokens[i] = 0;                       // Set last token as terminator
  return tokens;
}



 /* Prints all tokens. */

 void print_tokens(char **tokens)
 {
   int i;
   for (i = 0; tokens[i] != 0; i++) {

     printf("%s ",tokens[i]);       // Print every token
   }
 }



 /* Frees all tokens and the vector containing themx. */

 void free_tokens(char **tokens)
 {
   int i;

   for (i = 0; tokens[i] != 0; i++)
     {
       free(tokens[i]);             // Free all allocated memory for tokens
     }
   free(tokens);      
 }
