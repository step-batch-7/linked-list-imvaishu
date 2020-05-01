#ifndef _NUMBERS_H
#define _NUMBERS_H

#include "list.h"

char take_operation_to_perform(void);

void take_input(int *value);

Status choose_operation(List_ptr list,char operation);

#endif