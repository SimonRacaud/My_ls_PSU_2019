/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list
*/

#include "my_ls.h"

void get_max_owner_len(file_t *files, int size)
{
    int max_user_len = 0;
    int max_group_len = 0;
    int len;

    for (int i = 0; i < size; i++) {
        len = my_strlen(files[i].owner_user);
        if (len > max_user_len)
            max_user_len = len;
        len = my_strlen(files[i].owner_group);
        if (len > max_group_len)
            max_group_len = len;
    }
    for (int i = 0; i < size; i++) {
        files[i].max_len_owner_user = max_user_len;
        files[i].max_len_owner_group = max_group_len;
    }
}

void get_link_max_size(file_t *files, int size)
{
    int max_len = 0;
    int len = 0;

    for (int i = 0; i < size; i++) {
        len = my_nbrlen(files[i].link);
        if (len > max_len)
            max_len = len;
    }
    for (int i = 0; i < size; i++) {
        files[i].link_max_size = max_len;
    }
}

static void size_eval_len(file_t *file, int *max_len)
{
    int len = 0;

    if (file->type == 'c') {
        len = my_nbrlen(file->minor) + my_nbrlen(file->size) + 2;
        if (len > *max_len)
            *max_len = len;
    } else {
        len = my_nbrlen(file->size);
        if (len > *max_len)
            *max_len = len;
    }
}

void get_size_max_size(file_t *files, int size)
{
    int max_len = 0;

    for (int i = 0; i < size; i++) {
        size_eval_len(&files[i], &max_len);
    }
    for (int i = 0; i < size; i++) {
        files[i].size_max_len = max_len;
    }
}
