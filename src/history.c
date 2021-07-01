#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List *init_history() {
  List *list = (List*)malloc(sizeof(Item)*100);
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str) {
  Item *item_added = (Item*)malloc(sizeof(Item));
  Item *temp = list->root;
  int count = 1;  //count position in the list

  item_added->str = str;
  item_added->next = NULL;

  //if its a new list
  if (temp == NULL) {
    list->root = item_added;
    item_added->id = count;
  }
  else {  //iterate to next open spot
    while (temp->next != NULL) {
      temp = temp->next;
      count++;
    }
    temp->next = item_added;
    item_added->id = count + 1;
  }
}


char *get_history(List *list, int id) {
  if (list->root == NULL)
    return "List is empty";

  Item *temp = list->root;

  while (temp != NULL) {
    if (temp->id == id)
      return temp->str;
    temp = temp->next;
  }
  return '\0'; 
}

void print_history(List *list) {
  Item *temp = list->root;

  while (temp != NULL) {
    printf("%d: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list) {
  Item *temp1;    //two temps needed to iterate and free history
  Item *temp2;
  temp2 = list->root;

  while (temp2 != NULL) {
    temp1 = temp2;
    temp2 = temp2->next;
    free(temp1);
  }
  free(list);
}
