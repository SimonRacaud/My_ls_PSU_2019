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
    int space_minor = (file->size_max_len - (len_major + len_minor) - 2) / 2;
    int space_major = (file->size_max_len - (len_major + len_minor) - 2) / 2;

    if (file->type == 'c' || file->type == 'b') {
        if ((file->size_max_len - (len_major + len_minor) - 2) % 2 != 0)
            space_major++;
        for (int i = 0; i < space_major; i++)
            my_putchar(' ');
        my_printf("%u", file->major);
        my_putstr(", ");
        for (int i = 0; i < space_minor; i++)
            my_putchar(' ');
        my_printf("%u ", file->minor);
    } else {
        for (int i = my_nbrlen(file->size); i < file->size_max_len; i++)
            my_putchar(' ');
        my_put_nbr(file->size);
        my_putchar(' ');
    }
}

int get_sum_nb_block(file_t *files, int size)
{
    int blocks = 0;

    for (int i = 0; i < size; i++) {
        blocks += files[i].nb_block_alloc;
    }
    return (blocks / 2);
}
