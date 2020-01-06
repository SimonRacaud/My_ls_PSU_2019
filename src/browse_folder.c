/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Browse folder
*/

#include "my_ls.h"

int browse_folder(config_t *config, const char *folder)
{
    DIR *dir = opendir(folder);

    if (!dir) {
        my_putstr_error("ERROR: open dir\n");
        return EXIT_SUCCESS;
    }
    if (get_files(config, dir) == EXIT_ERROR)
        return EXIT_ERROR;
    // sort
    // display
    if (closedir(dir) == -1) {
        my_putstr_error("ERROR : close dir\n");
        return EXIT_ERROR;
    }
    // recursive call
    return EXIT_SUCCESS;
}
