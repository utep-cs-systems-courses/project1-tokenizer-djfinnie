#include <stdio.h>
#include "tokenizer.h"
#include <string.h>

int main()
{
  char s[] = "     my dog is flea free";
  puts("Welcome!");

  printf("\nString: %s ", s);
  printf("\nFirst non space char: %c\n", *word_start(&s[0]));

  printf("Word terminator: %c\n", *word_terminator(&s[0]));

  printf("\nNumber of words in %s - ", s);
  printf("%d\n", count_words(&s[0]));

  printf("\nCopy string: %s\n", s);
  printf("Copied: %s\n", *copy_str(&s[0], 24));


  return 0;
}
