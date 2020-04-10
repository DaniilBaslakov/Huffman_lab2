#include "unical.h"
#include "huffman.h"

void    increase_freq(char str)
{
    int i;

    i = 0;
    while (i < 256)
    {
        if (s_symbol.symb[i] == str)
            break;
        i++;
    }
    s_symbol.freq[i] += 1;
}

int    check_symb(char str)
{
    int i;

    i = 0;
    while (i < 256)
    {
        if (s_symbol.symb[i++] == str)
            return (1);
    }
    return (0);    
}

void    fill_arr(char *str, int *un)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[count])
    {
        if (check_symb(str[count]))
            increase_freq(str[count]);  
        else
        {
            s_symbol.symb[i] = str[count];
            s_symbol.freq[i] = 1;
            *un += 1;
            i++;
        }
        count++;
    }
    s_symbol.un = *un;
    s_symbol.symb[i + 1] = '\0';
}