#include "h_node.h"

#ifndef LINKED_LIST
#define LINKED_LIST

struct linked_list{
      struct h_node head;
      struct linked_list *next;
};

#endif
