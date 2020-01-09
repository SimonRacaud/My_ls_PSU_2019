/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** Task06
*/

#include "my.h"

static char alpha_in_upper(char c)
{
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int my_strcmp_nocase(char const *s1, char const *s2)
{
    int size = my_strlen(s1);
    int i = 0;

    if (my_strlen(s2) > size)
        size = my_strlen(s2);
    while (i < size) {
        if ((alpha_in_upper(s1[i]) - alpha_in_upper(s2[i])) != 0) {
            return (alpha_in_upper(s1[i]) - alpha_in_upper(s2[i]));
        }
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
        i++;
    }
    return (0);
}
