//source code https://habr.com/ru/post/144200/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "huffman.h"
#include "pQueue.h"
#include "unical.h"

void    traverseTree(htNode *treeNode, hlTable **table, int k, char code[256])
{
    if (treeNode->left == NULL && treeNode->right == NULL)
    {
        code[k] = '\0';
        hlNode *node;

        node = (hlNode*)malloc(sizeof(hlNode));
        node->code = (char *)malloc(sizeof(char)*(strlen(code) + 1));
        strcpy(node->code, code);
        node->symbol = treeNode->symbol;
        node->next = NULL;
        printf("\n[%c] [code]: [%s]\n", node->symbol, node->code);
        if ((*table)->first == NULL)
        {
            (*table)->first = node;
            (*table)->last = node;
        }
        else
        {
            (*table)->last->next = node;
            (*table)->last = node;
        }
    }

    if (treeNode->left != NULL)
    {
        code[k] = '0';
        printf("\n[left]\n");
        traverseTree(treeNode->left, table, k + 1, code);
    }
    if (treeNode->right != NULL)
    {
        code[k] = '1';
        printf("\n[right]\n");
        traverseTree(treeNode->right, table, k + 1, code);
    }
}

hlTable*    buildTable(htTree *huffmanTree)
{
    hlTable *table;
    char    code[256];
    int     k;

    k = 0;
    table = (hlTable*)malloc(sizeof(hlTable));
    table->first = NULL;
    table->last = NULL;
    traverseTree(huffmanTree->root, &table, k, code);
    return (table); 
}

htTree*     buildTree(char *inputString)
{
    pQueue *huffmanQueue;
    int i;
    int un;

    un = 0;
    i = 0;
    initPQueue(&huffmanQueue);
    fill_arr(inputString, &un);

    //writing queue nodes type htNode
    while (s_symbol.symb[i])
    {
        htNode *node;

        node = (htNode*)malloc(sizeof(htNode));
        node->left = NULL;
        node->right = NULL;
        node->symbol = s_symbol.symb[i];
        printf("\n[symb: %c]\n", node->symbol);
        addPQueue(&huffmanQueue, node, s_symbol.freq[i]);
        i++;
    }

    while (huffmanQueue->size != 1)
    {
        int priority;
        htNode *left;
        htNode *right;
        htNode *newNode;

        newNode = (htNode*)malloc(sizeof(htNode));

        priority = huffmanQueue->first->priority;
        priority += huffmanQueue->first->next->priority;
        printf("\n[prioritty: %d]\n", priority);
        left = getPQueue(&huffmanQueue);
        right = getPQueue(&huffmanQueue);

        newNode->left = left;
        newNode->right = right;
        
        addPQueue(&huffmanQueue, newNode, priority);
    }
    htTree *tree;

    tree = (htTree*)malloc(sizeof(htTree));
    tree->root = getPQueue(&huffmanQueue);
    return (tree);
}

void    encode(hlTable *table, char *stringToEncode)
{
    hlNode *node;
    int i;

    i = 0;
    printf("\nEncoding\nInput string: %s\nEncoded string: \n", stringToEncode);
    while (stringToEncode[i])
    {
        node = table->first;
        while (node->symbol != stringToEncode[i])
			node = node->next;
		printf("%s", node->code);
        i++;
    }
    printf("\n");
}
void    decode(htTree *tree, char *stringToDecode);
