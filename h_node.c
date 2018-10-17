#include <stdlib.h>
#include <stdio.h>
#include "h_node.h"

/*struct h_node{
   int occurence;
   char character;
   struct h_node *left;
   struct h_node *right;
}*/

struct h_node empty_node() {
   struct h_node *newNode;

   if ((newNode = (struct h_node*)malloc(sizeof(*newNode))) == NULL) {
      perror("New node failed to allocate memory");
      exit(1);
   } else {
      newNode->occurence = 0;
      newNode->character = 'a';
      newNode->left = NULL;
      newNode->right = NULL;
   }
   return *newNode;
}
