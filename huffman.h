#pragma once
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

//The Haffman tree node
typedef struct      _htNode
{
    char            symbol;
    struct _htNode  *left;
    struct _htNode  *right;
}                   htNode;

//The Haffman tree
typedef struct  _htTree
{
    htNode      *root;
}               htTree;

//The Haffman node table
typedef struct      _hlNode
{
    char            symbol;
    char            *code;
    struct  _hlNode *next;
}                   hlNode;

//The Haffman table code symbols
typedef struct  _hlTable
{
    hlNode      *first;
    hlNode      *last;
}               hlTable;

htTree* buildTree(char *inputString);
hlTable* buildTable(htTree *huffmanTree);
void encode(hlTable *table, char *stringToEncode);
void decode(htTree *tree, char *stringToDecode);

#endif