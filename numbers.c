#include <stdio.h>
#include "list.h"
#include "numbers.h"

char take_operation_to_perform(void)
{
  char option;
  printf("Please enter the alphabet of the operation you would like to perform\n");
  scanf("%c", &option);
  while ((getchar()) != '\n');
  return option;
}

void take_input(int *value,char *text)
{
  printf("%s\n",text);
  scanf("%d",value);
  while ((getchar()) != '\n'); 
}

Status choose_operation(List_ptr list,char operation)
{
 int value;
 int position;
 switch (operation)
  {
  case 'a':
    take_input(&value,INPUT_TEXT);
    return add_to_end(list, value);
    break;
  case 'b':
     take_input(&value,INPUT_TEXT);
     return add_to_start(list,value);
     break;
  case 'c':
     take_input(&value,INPUT_TEXT);
     take_input(&position,POSITION_TEXT);
     return insert_at(list,value,position);
     break;
  case 'd':
     take_input(&value,INPUT_TEXT);
     return add_unique(list,value);
     break;
  case 'e':
     return remove_from_start(list);
     break;      
  case 'l':
     display(list);
     return Success;
     break;
  }
 return Failure;
}

int main(void)
{
  List_ptr list = create_list();
  char operation = take_operation_to_perform();
  Status status = 1;
  while(operation != 'm')
  {
  status = choose_operation(list,operation);
  printf("status %u\n",status);
  operation = take_operation_to_perform();
  }
  printf("status %u\n",status);
  return 0;
}