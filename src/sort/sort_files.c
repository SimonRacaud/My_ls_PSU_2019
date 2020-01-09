/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** sort file list
*/

#include "my_ls.h"

static void reverse_sort(file_t *files, int size)
{
    file_t temp;

    for (int i = 0; i < (size / 2); i++) {
        temp = files[i];
        files[i] = files[(size - 1) - i];
        files[(size - 1) - i] = temp;
    }
}

static void sort_by_time(file_t *files, int size)
{
    quick_sort_files(files, 0, (size - 1));
    reverse_sort(files, size);
}

static void sort_by_name(file_t *files, int size)
{
    int is_sorted = 0;
    int idx = 0;
    file_t temp;

    while (!is_sorted) {
        if (my_strcmp_nocase(files[idx].name, files[idx + 1].name) > 0) {
            temp = files[idx];
            files[idx] = files[idx + 1];
            files[idx + 1] = temp;
            idx = 0;
        } else if (idx < (size - 2)) {
            idx++;
        } else {
            is_sorted = 1;
        }
    }
}

int sort_files(file_t *files, int size, config_t *config)
{
    if (size <= 1) {
        return EXIT_SUCCESS;
    }
    if (config->sort_mod_time_mode) {
        sort_by_time(files, size);
    } else {
        sort_by_name(files, size);
    }
    if (config->sort_reverse_mode && size > 1) {
        reverse_sort(files, size);
    }
    return EXIT_SUCCESS;
}
