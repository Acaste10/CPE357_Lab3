#include <stdlib.h>

struct linked_list{
      struct h_node head;
      struct h_node *next;
};

struct linked_list empty_l_list(){
   struct linked_list *newList = NULL;

   if ((newList = malloc (sizeof(struct linked_list))) == NULL) {
      perror("Empty Linked List failed to allocate memory");
      exit(1);
   } else {
      newList.head = empty_node();
      newList.next = NULL;
   }
   return newList;
}

int comes_before(struct linked_list *list, struct h_node node) {
   if (node.occurence == list->head.occurence) {
      return (node.character < list->head.character);
   }
   return node.occurence < list->head.occurence;
}

struct linked_list l_list_insert_sorted(struct linked_list *list, struct h_node node) {
   if (list == NULL) {
      struct linked_list *newHead = NULL;
      newHead = empty_l_list();

      newHead->head = node;
      newHead->next = NULL;
      return newHead;

   }
   if (comes_before(node, list)) {
      struct linked_list *newHead = NULL;
      newHead = empty_l_list();

      newHead->head = node;
      newHead->next = list->head;
      return newHead;
   } else {
      list->next = l_list_insert_sorted(list, node);
   }
   return list;
}

int l_list_len(struct linked_list *list) {
   if (list == NULL) {
      return 0;
   } else {
      return 1 + length(list->next);
   }
}
