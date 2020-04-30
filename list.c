#include <stdlib.h>
#include "list.h"

List_ptr create(void)
{
  List_ptr list = malloc(sizeof(List));

  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}