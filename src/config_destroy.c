/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** get the arguements of the program
*/

#include "my_ls.h"

void destroy_config(config_t *config)
{
    filelist_destroy(&config->path_list, 0);
}
