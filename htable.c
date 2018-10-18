#include "h_node.h"
#include "l_list.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define ASCII_LENGTH 128

void count_occurences(FILE *fp, int *arr) {
   int c_in = 0;

   while ((c_in = fgetc(fp)) != EOF) {
      arr[c_in] += 1;  
   }
}

int main(int argc, char *argv[]){
   struct h_node tree;
   int in_file[ASCII_LENGTH] = { 0 };
   FILE *fp;

   fp = NULL;

   /*if ((tree = (struct h_node*)malloc(sizeof(*tree))) == NULL) {
      perror("New tree failed to allocate memory");
      return 1;
   }*/

   if (argc == 1) {
      fprintf(stderr, "usage: htable <filename>");
      return 1;
   }
   
   fp = fopen(argv[1], "r");
   if (fp == NULL) {
      perror(argv[1]);
      return 1;
   }

   count_occurences(fp, in_file);
   tree = build_tree(in_file);
   
   return 0;
}
