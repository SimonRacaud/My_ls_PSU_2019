/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Get data about a file
*/

#include "my_ls.h"

extern const int SYMLINK_BUFSIZE;

static void get_symblink(file_t *file)
{
    file->symlink = malloc(sizeof(char) * SYMLINK_BUFSIZE);
    if (readlink(file->path, file->symlink, SYMLINK_BUFSIZE) == -1) {
        perror("ERROR: get symbolik link path\n");
        file->symlink = NULL;
    }
}

static void fill_file_data(file_t *file, stat_t *filestat)
{
    file->mode = filestat->st_mode;
    file->type = get_filetype_char(file->mode);
    file->link = filestat->st_nlink;
    file->inode = filestat->st_ino;
    file->uid = filestat->st_uid;
    file->gid = filestat->st_gid;
    file->size = filestat->st_size;
    file->last_mod = filestat->st_mtime;
    file->minor = DEVICE_MINOR(filestat->st_rdev);
    file->major = DEVICE_MAJOR(filestat->st_rdev);
    if (file->type == 'l') {
        get_symblink(file);
    } else
        file->symlink = NULL;
}

static int get_data(file_t *file, char *filename, const char *dir_path)
{
    stat_t filestat;

    file->path = merge_str(dir_path, filename);
    if (lstat(file->path, &filestat) == -1) {
        my_putstr_error("ERROR: get stat file: ");
        my_putstr_error(file->path);
        my_putstr_error("\n");
        return EXIT_ERROR;
    }
    fill_file_data(file, &filestat);
    file->name = filename;
    debug_display_file(file);
    return EXIT_SUCCESS;
}

int get_files_data(files_name_t *names, const char *path, file_t **files,
config_t *config)
{
    int size_names = count_notempty_node(names);
    int idx = 0;

    *files = malloc(sizeof(file_t) * size_names);
    if (!(*files))
        return EXIT_ERROR;
    for (file_node_t *n = config->path_list.next; n != NULL; n = n->next) {
        if (n->path != NULL && get_data(files[idx], n->path, path))
            return EXIT_ERROR;
        else if (n->path != NULL) {
            idx++;
        }
    }
    return EXIT_SUCCESS;
}
