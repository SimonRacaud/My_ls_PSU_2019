/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** sort file list
*/

#include "my_ls.h"

int sort_files(file_t *files, int size, config_t *config)
{

    return EXIT_SUCCESS;
}

void sort_path(config_t *config)
{
    int is_sorted = 0;
    int path_idx = 0;
    char *temp;

    if (config->nb_path <= 1)
        return;
    while (!is_sorted) {
        if (my_strcmp(config->path[path_idx], config->path[path_idx + 1]) > 0) {
            temp = config->path[path_idx];
            config->path[path_idx] = config->path[path_idx + 1];
            config->path[path_idx + 1] = temp;
            path_idx = 0;
        } else if (path_idx < (config->nb_path - 2)) {
            path_idx++;
        } else {
            is_sorted = 1;
        }
    }
}
