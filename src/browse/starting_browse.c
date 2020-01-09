/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Start browsing (folder get in arg of the program)
*/

#include "my_ls.h"

static int browse_sub(config_t *config, file_t *files)
{
    for (int idx = 0; idx < config->size_path_list; idx++) {
        if (files[idx].type == 'd' && browse_folder(config, files[idx].path))
            return EXIT_ERROR;
        else if (files[idx].type != 'd') {
            printf("DISP %d \n", config->size_path_list);
            display_file_data(&files[idx], config);
        }
    }
    return EXIT_SUCCESS;
}

int starting_browse(config_t *config)
{
    int ret = EXIT_SUCCESS;
    file_t *files = NULL;

    ret = remove_nonexistant_files(&config->path_list);
    if (ret == EXIT_ERROR2)
        return EXIT_ERROR;
    else if (ret == EXIT_ERROR)
        config->exit_status = EXIT_ERROR;
    config->size_path_list = count_notempty_node(&config->path_list);
    if (get_files_data(&config->path_list, "", &files))
        return EXIT_ERROR;
    sort_files(files, config->size_path_list, config);
    if (config->directory_mode) {
        display_files_data(files, config->size_path_list, config, "");
    } else if (browse_sub(config, files) == EXIT_ERROR)
        return EXIT_ERROR;
    destroy_file_array(files, config->size_path_list);
    return config->exit_status;
}
