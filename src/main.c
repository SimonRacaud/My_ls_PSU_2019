/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** main function
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

int usage(int status)
{
    my_putstr("Usage: ls [OPTIONS..] [FILE..]\n");
    my_putstr("List information about the FILEs");
    my_putstr(" (the current directory by default).\n");
    my_putstr("\nOPTIONS:\n");
    my_putstr("  -l\tList mode : display more informations.\n");
    my_putstr("  -R\tRecursive mode : display files recursively.\n");
    my_putstr("  -d\tDisplay the directory(ies).\n");
    my_putstr("  -r\tReversed display mode.\n");
    my_putstr("  -t\tSort by modification time. (newest first)\n");
    return status;
}

int main(int argc, char **argv)
{
    config_t config;

    if (argc == 2) {
        if (!my_strcmp(argv[1], "-h") || !my_strcmp(argv[1], "--help"))
            return usage(EXIT_SUCCESS);
    }
    if (get_argument(&config, argc, argv) == EXIT_ERROR)
        return EXIT_ERROR;
    debug_display_config(&config);
    if (browse_folders(&config) == EXIT_ERROR)
        return EXIT_ERROR;
    destroy_config(&config);
    return EXIT_SUCCESS;
}
