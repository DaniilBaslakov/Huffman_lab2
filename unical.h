#pragma once
#ifndef UNICAL_H
#define UNICAL_H

struct              s_unical
{
    char            symb[256];
    int             freq[256];
    unsigned int    un;
}                   s_symbol;

void    increase_freq(char str);
int     check_symb(char str);
void    fill_arr(char *str, int *un);

#endif