/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Get the type of a file with this mode_t number
*/

#include "my_ls.h"

/*
S_IFMT = mask type
S_IFSOCK   0140000   socket
S_IFLNK    0120000   symbolic link
S_IFREG    0100000   regular file
S_IFBLK    0060000   block device
S_IFDIR    0040000   directory
S_IFCHR    0020000   character device
S_IFIFO    0010000   FIFO
*/

static const int NB_FILETYPE = 7;
static const char FILETYPE_CHAR[] =
{
    's',
    'l',
    '-',
    'b',
    'd',
    'c',
    'p',
    'n'
};
static const unsigned int FILETYPE_ID[] =
{
    S_IFSOCK,
    S_IFLNK,
    S_IFREG,
    S_IFBLK,
    S_IFDIR,
    S_IFCHR,
    S_IFIFO
};

char get_filetype_char(mode_t mode)
{
    unsigned int filetype = (mode & S_IFMT);

    for (int i = 0; i < NB_FILETYPE; i++) {
        if (filetype == FILETYPE_ID[i]) {
            return FILETYPE_CHAR[i];
        }
    }
    return FILETYPE_CHAR[NB_FILETYPE];
}
