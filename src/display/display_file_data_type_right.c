/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list : Display the type and the rights of a file
*/

#include "my_ls.h"

static const char RIGHT_CHAR[3] = {'r', 'w', 'x'};
static const mode_t USER_MASK[3] = {S_IRUSR, S_IWUSR, S_IXUSR};
static const mode_t GROUP_MASK[3] = {S_IRGRP, S_IWGRP, S_IXGRP};
static const mode_t EVERY_MASK[3] = {S_IROTH, S_IWOTH, S_IXOTH};

static void display_right(const mode_t mode)
{
    for (int i = 0; i < 3; i++) {
        if (mode & USER_MASK[i])
            my_putchar(RIGHT_CHAR[i]);
        else
            my_putchar('-');
    }
    for (int i = 0; i < 3; i++) {
        if (mode & GROUP_MASK[i])
            my_putchar(RIGHT_CHAR[i]);
        else
            my_putchar('-');
    }
    for (int i = 0; i < 3; i++) {
        if (mode & EVERY_MASK[i])
            my_putchar(RIGHT_CHAR[i]);
        else
            my_putchar('-');
    }
}

void display_type_and_right(const file_t *file)
{
    my_putchar(file->type);
    display_right(file->mode);
    my_putchar(' ');
}
