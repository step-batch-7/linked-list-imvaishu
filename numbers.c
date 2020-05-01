#include <stdio.h>
#include "list.h"

void take_operation_to_perform(char *operation)
  {
   printf("Please enter the alphabet of the operation you would like to perform\n");
   scanf("%c",operation);
  }

void take_input(int *value)
{
  printf("Please enter a value...\n");
  scanf("%d",value);
}

Status choose_operation(List_ptr list)
{
 char operation;
 int value;
 take_operation_to_perform(&operation);
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
     break;
  }
}

int main(void)
{
  List_ptr list = create_list();
  Status status = choose_operation(list);
  status = 1 ? printf("Success\n") : printf("failure\n");
  return 0;
}