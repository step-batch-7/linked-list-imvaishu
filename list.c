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

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;

  return new_node;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  Status status = Success;
  return status;
}

Status add_to_start(List_ptr list,int value)
{
  Node_ptr new_node = create_node(value);
  Node_ptr previous_node = list->head;
  list->head = new_node;
  list->head->next = previous_node;
  list->count++;
  Status status = Success;
  return status;
}

void display(List_ptr list)
{
  Node_ptr p_walk = list->head;
  while(p_walk != NULL)
  {
    printf("%d\n",p_walk->value);
    p_walk = p_walk->next;
  }
} 
