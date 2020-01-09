/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list
*/

#include "my_ls.h"

static void display_line(const file_t *file)
{
    display_type_and_right(file);
    display_link(file);
    display_owner(file);
    display_size(file);
    display_lastmod_time(file);
    for (int i = 0; file->name[i] != '\0'; i++) {
        my_putchar(file->name[i]);
    }
    if (file->type == 'l')
        my_printf(" -> %s", file->symlink);
    my_putchar('\n');
}

static int get_sum_nb_block(file_t *files, int size)
{
    int blocks = 0;

    for (int i = 0; i < size; i++) {
        blocks += files[i].nb_block_alloc;
    }
    return (blocks / 2);
}

static void list_display(file_t *files, int size, config_t *config)
{
    get_max_owner_len(files, size);
    get_link_max_size(files, size);
    get_size_max_size(files, size);
    if (!config->directory_mode)
        my_printf("total %d\n", get_sum_nb_block(files, size));
    for (int i = 0; i < size; i++) {
        display_line(&files[i]);
    }
}

static void standard_display(file_t *files, int size)
{
    for (int i = 0; i < size; i++) {
        my_putstr(files[i].name);
        my_putchar('\n');
    }
}

int display_files_data(file_t *files, int size, config_t *config,
const char *pathdir)
{
    static int is_first = 1;

    if (config->recusif_mode && !config->directory_mode) {
        if (!is_first)
            my_putchar('\n');
        else
            is_first = 0;
        my_printf("%s:\n", pathdir);
    }
    if (config->list_mode) {
        list_display(files, size, config);
    } else {
        standard_display(files, size);
    }
    return EXIT_SUCCESS;
}
