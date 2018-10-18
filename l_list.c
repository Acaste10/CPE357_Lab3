#include <stdlib.h>
#include <stdio.h>
#include "l_list.h"
#include "h_node.h"

/*struct linked_list{
      struct h_node head;
      struct h_node *next;
}*/

struct linked_list *empty_l_list(){
   struct linked_list *newList = NULL;

   if ((newList = malloc (sizeof(*newList))) == NULL) {
      perror("Empty Linked List failed to allocate memory");
      exit(1);
   } 
   /*else {
      newList->head = empty_node();
      newList->next = NULL;
   }*/
   return newList;
}

struct linked_list *make_l_list(struct linked_list *list, struct h_node node) {
   struct linked_list *newHead = NULL;
   newHead = empty_l_list();

   newHead->head = node;
   newHead->next = list;
   return newHead;
}

int comes_before(struct h_node node, struct linked_list *list) {
   if (node.occurence == list->head.occurence) {
      return (node.character < list->head.character);
   }
   return node.occurence < list->head.occurence;
}

struct linked_list *l_list_insert_sorted(struct linked_list *list, struct h_node node) {
   /*if (list == NULL) {
      perror("NULL 'list' given for insert sorted");
      exit(1);
   }*/
   if (list == NULL){
      struct linked_list *newHead = NULL;
      newHead = empty_l_list();

      newHead->head = node;
      newHead->next = NULL;
      return newHead;
   }
   if (comes_before(node, list)) {
      return make_l_list(list, node);
   } else {
      list->next = l_list_insert_sorted(list->next, node);
   }
   return list;
}

int l_list_len(struct linked_list *list) {
   if (list == NULL) {
      return 0;
   } else {
      return 1 + l_list_len(list->next);
   }
}

struct linked_list *l_list_remove(struct linked_list *list) {
   if (list == NULL) {
      perror("NULL linked list given for remove");
      exit(1);
   } else {
      struct linked_list *temp = list->next;
      return temp;
   }
}

/*int main(){
   struct linked_list *newList = NULL;
   //struct linked_list *newList = NULL;
   //l_list_len(newList);
   //struct h_node newNode = empty_node();
   //newList = l_list_insert_sorted(newList, newNode);
   struct h_node otherNode1 = make_node(3, 'c', NULL, NULL);
   newList = l_list_insert_sorted(newList, otherNode1);
   struct h_node otherNode2 = make_node(1, 'b', NULL, NULL);
   newList = l_list_insert_sorted(newList, otherNode2);
   struct h_node otherNode3 = make_node(3, 'a', NULL, NULL);
   newList = l_list_insert_sorted(newList, otherNode3);
   newList = l_list_remove(newList);
   newList = l_list_remove(newList);
   newList = l_list_remove(newList);
   free(otherNode1);

   return 0;
}*/
