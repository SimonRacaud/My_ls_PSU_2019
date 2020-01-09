/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Start browsing (folder get in arg of the program)
*/

#include "my_ls.h"

static int test_opendir(file_node_t *file_node)
{
    DIR *dir = opendir(file_node->path);

    if (!dir && errno != ENOTDIR) {
        my_putstr_error("ls: cannot access '");
        my_putstr_error(file_node->path);
        my_putstr_error("': No such file or directory\n");
        file_node->path = NULL;
        return EXIT_ERROR;
    } else if (dir && closedir(dir) == -1) {
        my_putstr_error("ERROR : close dir\n");
    }
    return EXIT_SUCCESS;
}

static void remove_nonexistant_files(config_t *config)
{
    for (file_node_t *n = config->path_list.next; n != NULL; n = n->next) {
        if (test_opendir(n) == EXIT_ERROR) {
            n->path = NULL;
        }
    }
    if (count_notempty_node(&config->path_list) == 0) {
        filelist_push(&config->path_list, "./");
    }
}

int starting_browse(config_t *config)
{
    file_t *files = NULL;
    file_node_t *node = config->path_list.next;

    remove_nonexistant_files(config);
    config->size_path_list = count_notempty_node(&config->path_list);
    if (get_files_data(&config->path_list, "", &files, config))
        return EXIT_ERROR;
    sort_files(files, config->size_path_list, config);
    if (config->directory_mode) {
        display_files_data(files, config->size_path_list, config, "");
    } else {
        for (int idx = 0; idx < config->size_path_list; idx++) {
            if (browse_folder(config, files[idx].path))
                return EXIT_ERROR;
        }
    }
    destroy_file_array(files, config->size_path_list);
    return EXIT_SUCCESS;
}
