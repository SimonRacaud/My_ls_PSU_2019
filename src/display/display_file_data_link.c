/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list : Display the number of link
*/

#include "my_ls.h"

void display_link(const file_t *file)
{
    int len_link = my_nbrlen(file->link);

    for (int i = len_link; i < file->link_max_size; i++)
        my_putchar(' ');
    my_put_nbr(file->link);
    my_putchar(' ');
}
