#include <stdlib.h>
#include <stdio.h>
#include "h_node.h"
#include "l_list.h"

/*struct h_node{
   int occurence;
   char character;
   struct h_node *left;
   struct h_node *right;
}*/

struct h_node empty_node() {
  struct h_node *newNode;

  if ((newNode = (struct h_node *)malloc(sizeof(*newNode))) == NULL) {
    perror("New node failed to allocate memory");
    exit(1);
  } /*else {
     newNode->occurence = 0;
     newNode->character = 'a';
     newNode->left = NULL;
     newNode->right = NULL;
  }*/
  return *newNode;
}

struct h_node make_node(int occurence, char character, struct h_node *left,
                        struct h_node *right) {
  struct h_node *newNode;

  if ((newNode = (struct h_node *)malloc(sizeof(*newNode))) == NULL) {
    perror("New node failed to allocate memory");
    exit(1);
  } else {
    newNode->occurence = occurence;
    newNode->character = character;
    newNode->left = left;
    newNode->right = right;
  }
  return *newNode;
}

int n_comes_before(struct h_node *node1, struct h_node *node2) {
  if (node1->occurence == node2->occurence) {
    return (node1->character < node2->character);
  }
  return node1->occurence < node2->occurence;
}

struct h_node make_branch(struct h_node *node1, struct h_node *node2) {
  if (n_comes_before(node1, node2)) {
    if (node1->character < node2->character) {
      return make_node(node1->occurence + node2->occurence, node1->character,
                       node1, node2);
    } else {
      return make_node(node1->occurence + node2->occurence, node2->character,
                       node1, node2);
    }
  } else {
    if (node1->character < node2->character) {
      return make_node(node1->occurence + node2->occurence, node1->character,
                       node2, node1);
    } else {
      return make_node(node1->occurence + node2->occurence, node2->character,
                       node2, node1);
    }
  }
}

struct h_node build_tree_helper(struct linked_list *list) {
  int len = 0;
  len = l_list_len(list);
  if (len == 0) {
    return empty_node();
  }
  if (len == 1) {
    return list->head;
  } else {
    struct h_node *tmp1 = &list->head;
    list = l_list_remove(list);
    struct h_node *tmp2 = &list->head;
    list = l_list_remove(list);
    struct h_node branch = make_branch(tmp1, tmp2);
    list = l_list_insert_sorted(list, branch);
    return build_tree_helper(list);
  }
}

struct h_node build_tree(int *arr) {
  int i;
  struct linked_list *newList = NULL;

  for (i = 0; i < 128; i++) {
    if (arr[i] != 0) {
      struct h_node node = make_node(arr[i], (char)i, NULL, NULL);
      newList = l_list_insert_sorted(newList, node);
    }
  }
  return build_tree_helper(newList);
}
