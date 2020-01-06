/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Constants And Macro
*/

#include "my_ls.h"

/*
S_IFMT = mask
S_IFSOCK   0140000   socket
S_IFLNK    0120000   symbolic link
S_IFREG    0100000   regular file
S_IFBLK    0060000   block device
S_IFDIR    0040000   directory
S_IFCHR    0020000   character device
S_IFIFO    0010000   FIFO
*/

#define DEVICE_MAJOR(st_rdev) ((st_rdev >> 8) & 0xfff) \
| ((unsigned int) (st_rdev >> 32) & ~0xfff)

#define DEVICE_MINOR(st_rdev) (st_rdev & 0xff) \
| ((unsigned int) (st_rdev >> 12) & ~0xff)

const int NB_FILETYPE = 7;
const unsigned int FILETYPE_ID[] =
{
    S_IFSOCK,
    S_IFLNK,
    S_IFREG,
    S_IFBLK,
    S_IFDIR,
    S_IFCHR,
    S_IFIFO
};
