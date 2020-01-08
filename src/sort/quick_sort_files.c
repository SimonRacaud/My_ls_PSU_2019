/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** sort file list
*/

#include "my_ls.h"

static void swap(time_t *a, time_t *b)
{
    time_t t = *a;

    *a = *b;
    *b = t;
}

void quick_sort_files(file_t *files, int idx_begin, int idx_end)
{
    const int pivot = files[idx_begin].last_mod;
    int cur_left = idx_begin - 1;
    int cur_right = idx_end + 1;

    if (idx_begin - 1 == idx_end)
        return;
    while (1) {
        do {
            cur_left++;
        } while (files[cur_left].last_mod > pivot);
        do {
            cur_right--;
        } while (files[cur_right].last_mod < pivot);
        if (cur_left >= cur_right)
            break;
        swap(&files[cur_left].last_mod, &files[cur_right].last_mod);
    }
    quick_sort_files(files, idx_begin, cur_right - 1);
    quick_sort_files(files, cur_right + 1, idx_end);
}
