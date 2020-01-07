/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Get data about a file
*/

#include "my_ls.h"

static int get_data(file_t *file, char *path)
{
    
}

int get_files_data(char **path, file_t *files, int size, config_t *config)
{
    file_t *files = malloc(sizeof(file_t) * size);

    if (!file)
        return EXIT_ERROR;
    for (int i = 0; i < size; i++) {
        if (get_data(&files[i], path[i]))
            return EXIT_ERROR;
    }

    return EXIT_SUCCESS;
}
