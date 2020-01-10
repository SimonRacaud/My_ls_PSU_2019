/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include "my_ls.h"

void debug_display_config(config_t *config)
{
    file_node_t *node = config->path_list.next;

    my_putstr("--------------------\n");
    my_printf("\tList Mode [%d] \n", config->list_mode);
    my_printf("\tRecursif Mode [%d] \n", config->recusif_mode);
    my_printf("\tDir Mode [%d] \n", config->directory_mode);
    my_printf("\tSort rev Mode [%d] \n", config->sort_reverse_mode);
    my_printf("\tSort modif time Mode [%d] \n", config->sort_mod_time_mode);
    my_printf("\n\tNB PATH: [%d] \n", count_notempty_node(&config->path_list));
    while (node != NULL) {
        if (node->path != NULL)
            my_printf("\tPath: {%s} \n", node->path);
        node = node->next;
    }
    my_putstr("--------------------\n");
}

void debug_display_file(file_t *filedata)
{
    my_printf("Name: %s\n", filedata->name);
    my_printf("Path: %s\n", filedata->path);
    if (filedata->symlink != NULL)
        my_printf("Symlink: %s\n", filedata->symlink);
    my_printf("Type: %c\n", filedata->type);
    my_printf("Hard Link: %u\n", filedata->link);
    my_printf("Inode: %u\n", filedata->inode);
    my_printf("Size: %u\n", filedata->size);
    if (!filedata->minor && !filedata->major) {
        my_printf("Minor: N/A\n");
        my_printf("Major: N/A\n");
    } else {
        my_printf("Minor: %u\n", filedata->minor);
        my_printf("Major: %u\n", filedata->major);
    }
    my_printf("UID: %s\n", filedata->owner_user);
    my_printf("GID: %s\n", filedata->owner_group);
    my_printf("Time last mode: %u\n", filedata->last_mod);
    my_putstr("--------------------\n");
}

int my_ls(int argc, char **argv)
{
    config_t config;

    if (get_argument(&config, argc, argv) == EXIT_ERROR)
        return EXIT_ERROR;
    if (starting_browse(&config) == EXIT_ERROR)
        return EXIT_ERROR;
    destroy_config(&config);
    return EXIT_SUCCESS;
}
