#include <stdio.h>
#include "list.h"

char take_operation_to_perform(void)
{
  char option;
  printf("Please enter the alphabet of the operation you would like to perform\n");
  scanf("%c", &option);
  while ((getchar()) != '\n');
  return option;
}

void take_input(int *value)
{
  printf("Please enter a value...\n");
  scanf("%d",value);
  while ((getchar()) != '\n'); 
}

Status choose_operation(List_ptr list,char operation)
{
 int value;
 Status status = 0;
 switch (operation)
  {
  case 'a':
    take_input(&value);
    return add_to_end(list, value);
    break;
  case 'b':
     take_input(&value);
     return add_to_start(list,value);
     break;
  case 'l':
     display(list);
     status = 1;
     return status;
     break;
  }
 return status;
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
  status = 0;
  printf("status %u\n",status);
  return 0;
}