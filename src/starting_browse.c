/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Start browsing (folder get in arg of the program)
*/

#include "my_ls.h"

static int test_opendir(config_t *config, int folder_idx)
{
    DIR *dir = opendir(config->path[folder_idx]);

    if (!dir && errno != ENOTDIR) {
        my_putstr_error("ls: cannot access '");
        my_putstr_error(config->path[folder_idx]);
        my_putstr_error("': No such file or directory\n");
        config->path[folder_idx] = NULL;
        return EXIT_ERROR;
    }
    if (errno != ENOTDIR && closedir(dir) == -1) {
        my_putstr_error("ERROR : close dir\n");
    }
    return EXIT_SUCCESS;
}

static void remove_nonexistant_files(config_t *config)
{
    int idx = 0;

    for (unsigned int i = 0; i < config->nb_path; i++) {
        if (test_opendir(config, i))
            config->path[i] = NULL;
    }
    for (unsigned int i = 0; i < config->nb_path; i++) {
        if (config->path[idx] == NULL && config->path[i] != NULL) {
            config->path[idx] = config->path[i];
            config->path[i] = NULL;
            idx++;
        } else if (config->path[i] != NULL)
            idx++;
    }
    config->nb_path = idx;
}

int starting_browse(config_t *config)
{
    file_t *files = NULL;

    remove_nonexistant_files(config);
    if (config->directory_mode) {
        if (get_files_data(config->path, files, config->nb_path, config))
            return EXIT_ERROR;
        // Sort files
        display_files_data(files, config->nb_path, &config); // Display files data
    } else {
        for (int i = 0; i < config->nb_path; i++) {
            if (config->path[i] == NULL)
                continue;
            else if (browse_folder(config->path[i], config))
                return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}
