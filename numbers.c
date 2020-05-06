#include <stdio.h>
#include "list.h"
#include "numbers.h"

void display_done(Status current_status) {
  if(current_status == 1){
  printf("Done\n");
  }
  else
  {
  printf("Fail\n");
  }
} 

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
  case 'f':
     return remove_from_end(list);
     break; 
  case 'g':
     take_input(&position,POSITION_TEXT);
     return remove_at(list,position);
     break;
  case 'h':
     take_input(&value,INPUT_TEXT);
     return remove_first_occurrence(list,value);
     break;
  case 'i':
     take_input(&value,INPUT_TEXT);
     return remove_all_occurrences(list,value);
     break;
  case 'j':
     return clear_list(list);
     break;
  case 'k':
     take_input(&value,INPUT_TEXT);
     return is_number_exist(list,value);
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
  display_done(status);
  operation = take_operation_to_perform();
  }
  display_done(status);
  destroy_list(list);
  return 0;
}