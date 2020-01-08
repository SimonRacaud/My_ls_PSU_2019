/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list
*/

#include "my_ls.h"

void display_owner(const file_t *file)
{
    int len_user = my_strlen(file->owner_user);
    int len_group = my_strlen(file->owner_group);

    my_putstr(file->owner_user);
    for (int i = len_user; i < file->max_len_owner_user; i++)
        my_putchar(' ');
    my_putchar(' ');
    my_putstr(file->owner_group);
    for (int i = len_group; i < file->max_len_owner_group; i++)
        my_putchar(' ');
    my_putchar(' ');
}
