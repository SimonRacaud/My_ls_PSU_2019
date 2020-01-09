/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Browse folder
*/

#include "my_ls.h"

static int recursive_browse(file_t *files, int size, config_t *config)
{
    for (int idx = 0; idx < size; idx++) {
        if (files[idx].type == 'd' && browse_folder(config, files[idx].path))
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int browse_folder(config_t *config, const char *pathdir)
{
    files_name_t files_name = {NULL, NULL, 0};
    file_t *files = NULL;
    int nb_files_in_dir;
    int ret = get_subfiles_name(&files_name, pathdir);

    if (ret == EXIT_ERROR) {
        return EXIT_ERROR;
    } else if (ret == EXIT_ERROR2)
        config->exit_status = EXIT_ERROR;
    if (get_files_data(&files_name, pathdir, &files))
        return EXIT_ERROR;
    nb_files_in_dir = files_name.size;
    sort_files(files, nb_files_in_dir, config);
    display_files_data(files, nb_files_in_dir, config, pathdir);
    filelist_destroy(&files_name, 1);
    if (config->recusif_mode) {
        if (recursive_browse(files, nb_files_in_dir, config))
            return EXIT_ERROR;
    }
    destroy_file_array(files, nb_files_in_dir);
    return EXIT_SUCCESS;
}
