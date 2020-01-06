/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Constants And Macro
*/

#include "my_ls.h"

#define DEVICE_MAJOR(st_rdev) ((st_rdev >> 8) & 0xfff) \
| ((unsigned int) (st_rdev >> 32) & ~0xfff)

#define DEVICE_MINOR(st_rdev) (st_rdev & 0xff) \
| ((unsigned int) (st_rdev >> 12) & ~0xff)
