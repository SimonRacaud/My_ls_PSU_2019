/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Browse folder
*/

#include "my_ls.h"

static int test_opendir(config_t *config, int folder_idx)
{
    DIR *dir = opendir(config->path[folder_idx]);

    if (!dir) {
        my_putstr_error("ls: cannot access '");
        my_putstr_error(config->path[folder_idx]);
        my_putstr_error("': No such file or directory\n");
        config->path[folder_idx] = NULL;
        return EXIT_ERROR;
    }
    if (closedir(dir) == -1) {
        my_putstr_error("ERROR : close dir\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int browse_folders(config_t *config)
{
    sort_path(config);
    for (unsigned int i = 0; i < config->nb_path; i++) {
        test_opendir(config, i);
    }
    for (unsigned int i = 0; i < config->nb_path; i++) {
        if (config->path[i] == NULL) {
            continue;
        }
        if (config->directory_mode) {
            my_putstr(config->path[i]);
            my_putchar('\n');
        } else if (browse_folder(config, config->path[i]))
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
