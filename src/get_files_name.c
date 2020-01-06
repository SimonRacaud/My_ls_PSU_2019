/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Get the name of files in directory
*/

#include "my_ls.h"

int get_files_name(config_t *config, DIR *dir)
{
    struct dirent *dir_file;

    while ((dir_file = readdir(dir))) {
        if (!is_hidden_file(dir_file->d_name)) {
            my_printf("DIR %s \n", dir_file->d_name);
            my_printf("\tType %u \n", dir_file->d_type);
        }
    }
    return EXIT_SUCCESS;
}
