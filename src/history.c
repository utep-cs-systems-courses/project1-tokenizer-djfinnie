#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"



/* Initialize the linked list to keep the history. */
List *init_history()
{
  List *list = malloc(sizeof(List)); // Allocate memory for list

  list->root = malloc(sizeof(Item)); // Allocate memory for item in list

  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  int id = 1;
  Item *temp = list->root;

  while (temp->next != 0)  // Go to end of list
    { 
    temp = temp->next;
    id++;                  // Get id for new last item
    }

  short len = 0;
  int i;
  for (i = 0; *(str +i) != '\0'; i++)
    {
      len++;
    }
  
  temp->next = malloc(sizeof(Item)); // Allocate memory for item

  temp->next->str = copy_str(str, len); // Copy string into next item in list 

  temp->next->id = id; // Set id of current item
}


/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while (temp != 0)
    {
      if (temp->id == id) return temp->str; // If id is found return string within node
	temp = temp->next;
    }
  return "No item in list with inputted id";
}


/*Print the entire contents of the list. */

void print_history(List *list)
{
  Item *temp = list->root;
  temp = temp->next; // Root has null values so skip
  
  while (temp != 0)
    {
      printf("%d. %s", temp->id, temp->str); // Print id and string within each node
      temp = temp->next;
    }
}



/*Free the history list and the strings it references. */

void free_history(List *list)
{
  Item *temp = list->root;
  while (temp->next != 0)
    {
      free(temp->str);              // Free the string
      Item *next = temp->next;      // Pointer to next node
      free(temp);                   // Free original node
      temp = next;
    }
  free(temp->str);                  // Free the last node then free list
  free(temp);
  free(list);
}
