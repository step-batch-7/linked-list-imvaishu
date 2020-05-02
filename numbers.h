#ifndef _NUMBERS_H
#define _NUMBERS_H

#include "list.h"

#define INPUT_TEXT "Please enter a value..."
#define POSITION_TEXT "Please enter a position..."

char take_operation_to_perform(void);

void take_input(int *value,char *text);

Status choose_operation(List_ptr list,char operation);

#endif