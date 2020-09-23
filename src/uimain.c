#include <stdio.h>
#include "tokenizer.h"
#include <string.h>
#include "history.h"

int main()
{
  char input[500];

  List *list = init_history();

  printf("Welcome!");

  while (1) {

    printf("\nLet's tokenize!.. Select one of the following:\n");

    printf("1.Enter 'i' to add a sentence to history\n");
    printf("2.Enter 'h' to view all history\n");
    printf("3.Enter '!' followed by a list id number to recall history stored at that point.\n");
    printf("4.Enter 'q' to quit and clear history\n");

    printf(">$");

    fgets(input, 500, stdin);
    char *history;
    char **tokens;

    switch(input[0])
      {
	// Add string to history
       case 'i':
	  printf("Enter your sentence:\n>$");

          fgets(input, 100, stdin);

          char **tokens = tokenize(input);
	  
	  printf("- tokenized:\n");
          print_tokens(tokens);
          add_history(list, input);
          free_tokens(tokens);
	  break;

	  // Print all user inputted strings
       case 'h':
        print_history(list);
        break;

	// Get string stored at inputted id
       case '!':
	 history = get_history(list,atoi(input+1));
	 tokens = tokenize(history);

         printf("\nRetrieved history: %s\n", history);
	 printf("Retrieved history tokenized:\n");
	 if (*history == '\0') printf("\n------------No history stored at this id!-----------\n");

         print_tokens(tokens);
 	 free_tokens(tokens);
         break;

	 // Exit program
       case 'q':
	 printf("\nGone already?.. Adios :(\n");
	 free_history(list);
	 return 0;
	 break;
	 
	 // Invaild user input
       default:   
	 printf("ERROR. Please reread the input options! :)");
	
      }
    
  }
  return 0;
}
