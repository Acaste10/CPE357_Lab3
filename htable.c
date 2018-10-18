#include "h_node.h"
#include "l_list.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_LENGTH 128

void count_occurences(FILE *fp, int *arr) {
  int c_in = 0;

  while ((c_in = fgetc(fp)) != EOF) {
    arr[c_in] += 1;
  }
}

void character_codes(struct h_node tree, char *code, int index) {
  if (tree.left == NULL && tree.right == NULL) {
    printf("0x%02x: %s\n", tree.character, code);
  } else {
    if (tree.left != NULL) {
       index += 1;
       character_codes(*tree.left,strcat(code, "0"), index);
       code[index-1] = code[index+1];
       index -= 1;
    }
    if (tree.right != NULL) {
       index += 1;
       character_codes(*tree.right, strcat(code, "1"), index);
       code[index-1] = code[index+1];
    }
  }
}

int main(int argc, char *argv[]) {
  struct h_node tree;
  int i = 0;
  int in_file[ASCII_LENGTH] = { 0 };
  FILE *fp = NULL;
  char codes[1408];

  /*if ((tree = (struct h_node*)malloc(sizeof(*tree))) == NULL) {
     perror("New tree failed to allocate memory");
     return 1;
  }*/

  if (argc == 1) {
    fprintf(stderr, "usage: htable <filename>\n");
    return 1;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror(argv[1]);
    return 1;
  }

  count_occurences(fp, in_file);
  tree = build_tree(in_file);
  character_codes(tree, codes, i);

  return 0;
}
