/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** get the arguements of the program
*/

#include "my_ls.h"

static const char OPTIONS[] =
{
    'l',
    'R',
    'r',
    'd',
    't',
    '\0'
};

static void add_option(config_t *config, char option)
{
    if (option == 'l')
        config->list_mode = 1;
    if (option == 'R')
        config->recusif_mode = 1;
    if (option == 'r')
        config->sort_reverse_mode = 1;
    if (option == 'd')
        config->directory_mode = 1;
    if (option == 't')
        config->sort_mod_time_mode = 1;
}

static int eval_option(char *arg, config_t *config)
{
    if (arg[0] != '-')
        return -1;
    for (int i = 1; arg[i] != '\0'; i++) {
        if (search_char_in_str(OPTIONS, arg[i]) != -1) {
            add_option(config, arg[i]);
        } else {
            my_putstr_error("ls: invalid option -- '");
            write(2, &arg[i], 1);
            my_putstr_error("'\nTry 'ls --help' for more information.\n");
            return EXIT_ERROR;
        }
    }
    return EXIT_SUCCESS;
}

static void init_config(config_t *config)
{
    config->list_mode = 0;
    config->recusif_mode = 0;
    config->directory_mode = 0;
    config->sort_reverse_mode = 0;
    config->sort_mod_time_mode = 0;
    config->path_list.next = NULL;
    config->path_list.last = NULL;
    config->path_list.size = 0;
}

int get_argument(config_t *config, int argc, char **argv)
{
    int ret;

    init_config(config);
    for (int i = 1; i < argc; i++) {
        ret = eval_option(argv[i], config);
        if (ret == EXIT_ERROR)
            return EXIT_ERROR;
        else if (ret == -1 && filelist_push(&config->path_list, argv[i])) {
            return EXIT_ERROR;
        }
    }
    if (config->path_list.size == 0)
        filelist_push(&config->path_list, ".");
    return EXIT_SUCCESS;
}
