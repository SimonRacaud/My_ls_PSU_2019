/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include "my_ls.h"

void debug_display_config(config_t *config)
{
    my_printf("List Mode %d \n", config->list_mode);
    my_printf("Recursif Mode %d \n", config->recusif_mode);
    my_printf("Dir Mode %d \n", config->directory_mode);
    my_printf("Sort rev Mode %d \n", config->sort_reverse_mode);
    my_printf("Sort modif time Mode %d \n", config->sort_mod_time_mode);
    my_printf("\nNB PATH: %d \n", config->nb_path);
    for (unsigned int i = 0; i < config->nb_path; i++)
        my_printf("Path: %s \n", config->path[i]);
    my_putstr("\n");
}

int my_ls(int argc, char **argv)
{
    config_t config;

    if (get_argument(&config, argc, argv) == EXIT_ERROR)
        return EXIT_ERROR;
    debug_display_config(&config); // DEBUG
    if (starting_browse(&config) == EXIT_ERROR)
        return EXIT_ERROR;
    destroy_config(&config);
    return EXIT_SUCCESS;
}
