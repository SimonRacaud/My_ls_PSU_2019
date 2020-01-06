/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** main function
*/

#include "my_ls.h"

static int usage(int status)
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
    if (argc == 2) {
        if (!my_strcmp(argv[1], "-h") || !my_strcmp(argv[1], "--help"))
            return usage(EXIT_SUCCESS);
    }
    return my_ls(argc, argv);
}
