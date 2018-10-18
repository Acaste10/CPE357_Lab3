#include "h_node.h"

#ifndef LINKED_LIST
#define LINKED_LIST

struct linked_list{
      struct h_node head;
      struct linked_list *next;
};

struct linked_list *l_list_insert_sorted(struct linked_list *list, struct h_node node);
int l_list_len(struct linked_list *list);
struct linked_list *l_list_remove(struct linked_list *list);

#endif
