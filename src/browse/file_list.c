/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** File list
*/

#include "my_ls.h"

int filelist_push(files_name_t *list, char *path)
{
    file_node_t *new_path = malloc(sizeof(file_node_t));

    if (!new_path) {
        my_putstr_error("ERROR: malloc (in filelist_push)\n");
        return EXIT_ERROR;
    }
    new_path->next = NULL;
    new_path->path = path;
    if (list->last != NULL)
        list->last->next = new_path;
    else
        list->next = new_path;
    list->last = new_path;
    list->size++;
    return EXIT_SUCCESS;
}

static void filelist_destroy_nodes(file_node_t *node, int free_path)
{
    if (node == NULL)
        return;
    if (free_path)
        free(node->path);
    if (node->next != NULL) {
        filelist_destroy_nodes(node->next, free_path);
    }
    free(node);
}

int filelist_destroy(files_name_t *list, int free_path)
{
    if (list != NULL && list->next != NULL)
        filelist_destroy_nodes(list->next, free_path);
    list->size = 0;
    return EXIT_SUCCESS;
}

char *filelist_getnext_path(files_name_t *list)
{
    static file_node_t *node = NULL;

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

int count_notempty_node(files_name_t *list)
{
    int count = 0;

    for (file_node_t *n = list->next; n != NULL; n = n->next) {
        if (n->path != NULL)
            count++;
    }
    return count;
}
