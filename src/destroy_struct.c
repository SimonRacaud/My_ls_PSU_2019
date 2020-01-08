/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** get the arguements of the program
*/

#include "my_ls.h"

void destroy_config(config_t *config)
{
    filelist_destroy(&config->path_list, 0);
}

static void destroy_file(file_t *file)
{
    free(file->path);
    free(file->name);
    free(file->owner_user);
    free(file->owner_group);
    if (file->symlink != NULL)
        free(file->symlink);
}

void destroy_file_array(file_t *files, int size)
{
    for (int i = 0; i < size; i++) {
        destroy_file(&files[i]);
    }
    free(files);
}
