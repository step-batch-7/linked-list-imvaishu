#include <stdio.h>
#include "list.h"

void take_operation_to_perform(char *operation)
  {
   printf("Please enter the alphabet of the operation you would like to perform\n");
   scanf("%c",operation);
   while ((getchar()) != '\n'); 
  }

void take_input(int *value)
{
  printf("Please enter a value...\n");
  scanf("%d",value);
  while ((getchar()) != '\n'); 
}

Status choose_operation(List_ptr list)
{
 char operation;
 take_operation_to_perform(&operation);

 switch (operation)
  {
  int value;
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
     Status status = 1;
     return status;
     break;
  }
}

int main(void)
{
  List_ptr list = create_list();
  Status status = 1;
  while(1)
  {
  status = choose_operation(list);
  printf("Success\n");
  }
  printf("Failure\n");
  return 0;
}