/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Tools Funcitons
*/

#include "my_ls.h"

char *get_filename(const char *path)
{
    int pos_last_slash = -1;
    int len = -1;

    while (path[++len] != '\0') {
        if (path[len] == '/')
            pos_last_slash = len;
    }
    if (pos_last_slash == (len - 1))
        pos_last_slash = -1;
    return my_strdup((path + pos_last_slash + 1));
}

char *get_dirpath(const char *path)
{
    int pos_last_slash = -1;
    int len = -1;
    char *dirpath;

    while (path[++len] != '\0') {
        if (path[len] == '/')
            pos_last_slash = len;
    }
    if (pos_last_slash <= 1)
        pos_last_slash = (len - 1);
    dirpath = malloc(sizeof(char) * pos_last_slash + 1);
    if (!dirpath)
        return NULL;
    my_strncpy(dirpath, path, pos_last_slash);
    dirpath[pos_last_slash] = '\0';
    return dirpath;
}

char *merge_path_filename(const char *path, const char *filename)
{
    int sizea = my_strlen(path);
    int sizeb = my_strlen(filename);
    char *merge = malloc(sizeof(char) * (sizea + sizeb + 2));

    if (!merge) {
        my_putstr_error("ERORR: malloc : merge_str() \n");
        return NULL;
    }
    if (path[0] != '\0')
        my_strcpy(merge, path);
    if (path[sizea - 1] != '/' && path[0] != '\0' && filename[0] == '\0') {
        merge[sizea] = '/';
        sizea++;
    }
    if (filename[0] != '\0')
        my_strcpy(&merge[sizea], filename);
    merge[sizea + sizeb] = '\0';
    return merge;
}
