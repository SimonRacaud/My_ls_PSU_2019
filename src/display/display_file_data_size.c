/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list : Display the type and the rights of a file
*/

#include "my_ls.h"

void display_size(const file_t *file)
{
    int len_minor = my_nbrlen(file->minor);
    int len_major = my_nbrlen(file->major);
    int space_minor = file->size_max_len - len_major - 2;
    int space_major = file->size_max_len - len_minor - 2;

    if (file->type == 'c') {
        for (int i = len_major; i < space_major; i++)
            my_putchar(' ');
        my_printf("%u", file->major);
        my_putstr(", ");
        for (int i = len_minor; i < space_minor; i++)
            my_putchar(' ');
        my_printf("%u ", file->minor);
    } else {
        for (int i = my_nbrlen(file->size); i < file->size_max_len; i++)
            my_putchar(' ');
        my_put_nbr(file->size);
        my_putchar(' ');
    }
}
