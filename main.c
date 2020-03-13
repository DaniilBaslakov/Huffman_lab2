#include <stdio.h>
#include <stdlib.h>

#include "pQueue.h"
#include "huffman.h"
#include "unical.h"

int     main(int argc, char **argv)
{
    char    *str;
    htTree  *tree;
    hlTable *codeTable;

    str = "Hello, world!";
    if (argc == 2)
        str = argv[1];
    tree = buildTree(str);
    codeTable = buildTable(tree);
    encode(codeTable, str);
    decode(tree, "110111000101001111111010010010000110111010");
    return (0);
}