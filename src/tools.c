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
