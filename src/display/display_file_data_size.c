/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list : Display the type and the rights of a file
*/

#include "my_ls.h"

void display_size(file_t *file)
{
    if (file->type == 'c') {
        my_printf("%u, %u", file->major, file->minor);
    } else {
        my_putnbr(file->size);
    }
}
