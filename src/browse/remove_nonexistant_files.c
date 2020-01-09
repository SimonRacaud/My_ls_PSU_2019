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
        if (errno == ENOENT)
            my_putstr_error("': No such file or directory\n");
        else if (errno == EACCES)
            my_putstr_error("': Permission denied\n");
        else
            my_putstr_error("': Error\n");
        file_node->path = NULL;
        return EXIT_ERROR;
    } else if (dir && closedir(dir) == -1) {
        my_putstr_error("ERROR : close dir\n");
    }
    return EXIT_SUCCESS;
}

int remove_nonexistant_files(files_name_t *names)
{
    int ret = EXIT_SUCCESS;

    for (file_node_t *n = names->next; n != NULL; n = n->next) {
        if (test_opendir(n) == EXIT_ERROR) {
            n->path = NULL;
            ret = EXIT_ERROR;
        }
    }
    if (count_notempty_node(names) == 0) {
        return EXIT_ERROR2;
    }
    return ret;
}
