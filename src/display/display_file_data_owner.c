/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list
*/

#include "my_ls.h"

void display_owner(uid_t uid, gid_t gid)
{
    struct passwd *user = getpwuid(uid);
    struct group *group = getgrgid(gid);

    my_putstr(user->pw_name);
    my_putchar(' ');
    my_putstr(group->gr_name);
    my_putchar(' ');
}
