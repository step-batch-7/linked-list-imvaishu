#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));

  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while(p_walk != NULL)
  {
    printf("%d",p_walk->value);
    p_walk = p_walk->next;
  }
} 
