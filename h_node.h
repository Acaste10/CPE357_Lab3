#ifndef HUFFMAN_NODE
#define HUFFMAN_NODE

struct h_node{
   int occurence;
   char character;
   struct h_node *left;
   struct h_node *right;
};

struct h_node empty_node();

#endif
