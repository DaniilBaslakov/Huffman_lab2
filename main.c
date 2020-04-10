#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include "pQueue.h"
#include "huffman.h"
#include "unical.h"

unsigned int     bit_ascii(void)
{
    unsigned int un;
    unsigned int probability[8] = {2, 4, 8, 16, 32, 64, 128, 256};
    // unsigned int N[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    unsigned int i;

    un = s_symbol.un;
    printf("UN: %d\n", un);

    i = 0;
    while (probability[i])
    {
        if (un == probability[i])
        {
            return (i);
        }
        else if (un > probability[i] && un < probability[i + 1])
        {
            return (i + 2);
        }
        i++;
    }
    return (0);

}
int     main(int argc, char **argv)
{
    htTree  *tree;
    hlTable *codeTable;

    int     fd;
    char    buf;
    int     size;
    int     i;
    char    *arr;
    char    *str;
    
    i = 0;
    size = 0;
    str = "Hello, world!";
    if(argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while (read(fd, &buf, 1))
            size++;
        close(fd);
        fd = open(argv[1], O_RDONLY);
        arr = (char *)malloc(sizeof(char) * size + 1);
        while (read(fd, &buf, 1))
        {
            printf("\n%c\n", buf);
            arr[i++] = buf;
        }
        arr[i] = '\0';
        close(fd);
    }
    else
    {
        arr = malloc(sizeof(str) + 1);
        i = 0;
        while (str[i])
        {
            arr[i] = str[i];
            i++;
        }
        arr[i] = '\0';
    }
    
    tree = buildTree(arr);//str
    codeTable = buildTable(tree);
    // printf("BIT ASCII: %d\n", bit_ascii());
    printf("\nbit ASCII: %ld\n", (strlen(arr)) * bit_ascii());
    encode(codeTable, arr);//str
    // decode(tree, "110111000101001111111010010010000110111010"); 
    return (0);
}