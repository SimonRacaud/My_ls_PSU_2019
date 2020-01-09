/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Tools Funcitons
*/

#include "my_ls.h"

int search_char_in_str(const char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}

int is_hidden_file(char *file_name)
{
    if (file_name[0] == '.')
        return 1;
    return 0;
}

char *merge_path_filename(const char *stra, const char *strb)
{
    int sizea = my_strlen(stra);
    int sizeb = my_strlen(strb);
    char *merge = malloc(sizeof(char) * (sizea + sizeb + 2));

    if (!merge) {
        my_putstr_error("ERORR: malloc : merge_str() \n");
        return NULL;
    }
    if (stra[0] != '\0')
        my_strcpy(merge, stra);
    if (stra[sizea - 1] != '/' && stra[0] != '\0') {
        merge[sizea] = '/';
        sizea++;
    }
    if (strb[0] != '\0')
        my_strcpy(&merge[sizea], strb);
    merge[sizea + sizeb] = '\0';
    return merge;
}

char *my_strdup(char const *src)
{
    char *cpy = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (cpy == NULL)
        return (cpy);
    my_strcpy(cpy, src);
    return cpy;
}

int my_nbrlen(const int nbr)
{
    int len = 1;
    double nb = nbr;

    if (nb < 0)
        nb = -nb;
    while ((nb /= 10) >= 1) {
        len++;
    }
    return len;
}
