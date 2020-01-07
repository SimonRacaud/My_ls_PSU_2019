/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** File list
*/

#include "my_ls.h"

int filelist_push(files_name_t *list, char *path)
{
    file_name_t *new_path = malloc(sizeof(file_name_t));

    if (!new_path) {
        my_putstr_error("ERROR: malloc (in filelist_push)\n");
        return EXIT_ERROR;
    }
    new_path->next = NULL;
    new_path->path = path;
    list->last->next = new_path;
    list->last = new_path;
    return EXIT_SUCCESS;
}

static void filelist_remove_node(file_name_t *node)
{
    if (node == NULL)
        return;
    free(node->path);
    if (node->next != NULL) {
        filelist_remove_node(node->next);
    }
    free(node);
}

int filelist_destroy(files_name_t *list)
{
    if (list != NULL && list->next != NULL)
        filelist_remove_node(list->next);
}

char *filelist_getnext_path(files_name_t *list)
{
    static file_name_t *node = NULL;

    if (node == NULL) {
        node = list->next;
    } else {
        node = node->next;
    }
    if (node == NULL) {
        return NULL;
    } else {
        return node->path;
    }
}
