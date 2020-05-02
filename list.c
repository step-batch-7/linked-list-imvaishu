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

  return Success;
}

Status add_to_start(List_ptr list,int value)
{
  Node_ptr new_node = create_node(value);
  Node_ptr previous_node = list->head;
  list->head = new_node;
  list->head->next = previous_node;
  list->count++;
  
  return Success;
}

Status insert_at(List_ptr list, int value, int position) 
{
  if(position < 0 || position > list->count){
    return Failure;
  }
  if(position == 0) {
    return add_to_start(list, value);
  }
  if(position == list->count) {
    return add_to_end(list, value);
  }
  int count = 1;
  Node_ptr new_node = create_node(value);
  Node_ptr p_walk = list->head;
  while (count != position) {
    p_walk = p_walk->next;
    count++;
  }
  new_node->next = p_walk->next;
  p_walk->next = new_node;
  list->count++;
  
  return Success;
}

Status add_unique(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  for(int i = 0 ; i < list->count ; i++ )
  {
    if(p_walk->value == value){
      return Failure;
    }
      p_walk = p_walk->next;
    }
    return add_to_end(list,value);
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

Status remove_from_start(List_ptr list)
{
  Node_ptr first_element = list->head;
  if(list->head == NULL)
  {
    return Success;
  }
  list->head = first_element->next;
  list->count--;
  free(first_element);
  return Success;
}

Status remove_from_end(List_ptr list)
{
  Node_ptr last_element = list->last;
  Node_ptr previous_element;
  Node_ptr p_walk = list->head;
  int position = 0;
  if(list->head == NULL)
  {
    return Success;
  }
  if(list->count == 1)
  {
    free(list->head);
    list->head = NULL;
    list->count--;
    return Success;
  }
  while(position < list->count){
    if(position == (list->count - 2))
    {
     previous_element = p_walk;
    }
    p_walk = p_walk->next;
    position++;
  }
  list->last = previous_element;
  previous_element->next = NULL;
  list->count--;
  free(last_element);
  return Success;
}

 Status remove_at(List_ptr list,int position)
{
  Node_ptr p_walk = list->head;
  Node_ptr previous_element;
  Node_ptr remove_element;
  if(position <= 0 || position > list->count)
  {
    return Failure;
  }
  if(position == 1)
  {
    return remove_from_start(list); 
  }
  if(position == list->count)
  {
    return remove_from_end(list);
  }
  int count = 0;
  while(count < position){
    if(count == position - 2 )
    {
     previous_element = p_walk;
     remove_element = p_walk->next;
    }
    p_walk = p_walk->next;
    count++;
  }
  previous_element->next = p_walk;
  free(remove_element);
  list->count--;
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;

  for(int index = 1 ; index < list->count ; index++)
  {
    if(p_walk->value == value)
    {
      return remove_at(list,index);
    }
    p_walk = p_walk->next;
  }
  return Success;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;

  for(int index = 1 ; index <= list->count ; index++)
  {
    if(p_walk->value == value)
    {
      remove_at(list,index);
      index -= 1;
    }
    p_walk = p_walk->next;
  }
  return Success;
}