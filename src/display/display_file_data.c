/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list
*/

#include "my_ls.h"

static void display_line(const file_t *file)
{
    display_type_and_right(file->mode);
    my_printf("%d ");
    display_owner(file->uid, file->gid);
    display_size(file);
    my_putstr(file->name);
    if (file->type == 'l')
        my_printf(" -> %s", file->symlink);
    my_putchar('\n')
}

static void list_display(file_t *file, int size)
{
    my_printf("total %d\n", size);
    for (int i = 0; i < size; i++) {
        display_line(file[i]);
    }
}

static void standard_display(file_t *file, int size)
{
    for (int i = 0; i < size; i++) {
        my_putstr(file->name);
    }
}

int display_files_data(file_t *file, int size, config_t *config)
{
    if (config->list_mode) {
        list_display(file, size);
    } else {
        standard_display(file, size);
    }
    return EXIT_SUCCESS;
}
