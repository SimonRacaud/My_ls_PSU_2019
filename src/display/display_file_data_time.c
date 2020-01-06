/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list : Display the last modif time
*/

#include "my_ls.h"

void dipslay_lastmod_time(file_t *file)
{
    my_putstr(ctime(file->last_mod));
    my_putchar(' ');
}
