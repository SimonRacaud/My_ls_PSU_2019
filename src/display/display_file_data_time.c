/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Display file list : Display the last modif time
*/

#include "my_ls.h"

static void display_month_day(const char *format_time)
{
    int count_space = 0;

    for (int i = 4; format_time[i] != '\0'; i++) {
        if (format_time[i] == ' ' && format_time[i - 1] != ' ')
            count_space++;
        my_putchar(format_time[i]);
        if (count_space == 2)
            break;
    }
}

static void display_time(const char *format_time)
{
    for (int i = 11; i < 16; i++) {
        my_putchar(format_time[i]);
    }
}

static void display_year(const char *format_time)
{
    for (int i = 20; i < 24; i++) {
        my_putchar(format_time[i]);
    }
}

void display_lastmod_time(const file_t *file)
{
    char *format_time = ctime(&file->last_mod);
    time_t now = time(NULL);
    time_t six_month_seconds = 15778476;

    display_month_day(format_time);
    if (now - file->last_mod > six_month_seconds) {
        display_year(format_time);
    } else {
        display_time(format_time);
    }
    my_putchar(' ');
}
