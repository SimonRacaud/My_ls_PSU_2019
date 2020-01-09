/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Get the name of files in directory
*/

#include "my_ls.h"

int get_subfiles_name(files_name_t *names, const char *pathdir)
{
    DIR *dir = opendir(pathdir);
    struct dirent *dir_file;

    if (!dir) {
        my_putstr_error("ls: cannot access '");
        my_putstr_error(pathdir);
        my_putstr_error("': Permission denied\n");
        return EXIT_ERROR2;
    }
    while ((dir_file = readdir(dir))) {
        if (!is_hidden_file(dir_file->d_name)) {
            filelist_push(names, my_strdup(dir_file->d_name));
        }
    }
    if (closedir(dir) == -1) {
        my_putstr_error("ERROR : close dir\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}
