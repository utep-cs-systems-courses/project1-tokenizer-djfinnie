#include <stdio.h>
#include "tokenizer.h"
#include <string.h>

int main()
{
  char s[] = "     my dog is flea free";
  puts("Welcome!");

  printf("\nword_start:");
  printf("\nStart of string:%s ", s);
  printf("\nfirst non space char: %c\n", *word_start(&s[0]));

  printf("Word terminator: %c\n", *word_terminator(&s[0]));

  printf("Number of words in %s -", s);
  printf("%d", count_words(&s[0]));


  return 0;
}
