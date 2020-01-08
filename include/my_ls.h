/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2020
** File description:
** my ls header
*/

#ifndef H_MYLS
#define H_MYLS

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <pwd.h>
#include <dirent.h>
#include "my.h"

#define EXIT_ERROR 84

#define DEVICE_MAJOR(st_rdev) ((st_rdev >> 8) & 0xfff) \
| ((unsigned int) (st_rdev >> 32) & ~0xfff)

#define DEVICE_MINOR(st_rdev) (st_rdev & 0xff) \
| ((unsigned int) (st_rdev >> 12) & ~0xff)

typedef struct stat stat_t;

typedef struct file_node {
    struct file_node *next;
    char *path;
} file_node_t;

typedef struct files_name {
    file_node_t *next;
    file_node_t *last;
    unsigned int size;
} files_name_t;

typedef struct config {
    char sort_mod_time_mode;
    char sort_reverse_mode;
    char list_mode;
    char directory_mode;
    char recusif_mode;
    files_name_t path_list;
} config_t;

typedef struct file {
    char *name;
    char *path;
    char *symlink;
    mode_t mode;
    char type;
    nlink_t link;
    ino_t inode;
    uid_t uid;
    gid_t gid;
    off_t size;
    time_t last_mod;
    unsigned int minor;
    unsigned int major;
} file_t;

void debug_display_config(config_t *config); // DEBUG
void debug_display_file(file_t *filedata); // DEBUG

int my_ls(int argc, char **argv);

int starting_browse(config_t *config);
int browse_folder(config_t *config, const char *pathdir);

int sort_files(file_t *files, int size, config_t *config);
void quick_sort_files(file_t *files, int idx_begin, int idx_end);

int display_files_data(file_t *file, int size, config_t *config);
void display_type_and_right(file_t *file);
void display_owner(uid_t uid, gid_t gid);
void display_size(file_t *file);
void display_lastmod_time(file_t *file);

int get_files_data(files_name_t *names, const char *path, file_t **files,
config_t *config);

int search_char_in_str(const char *str, char c);
int is_hidden_file(char *file_name);
char *get_filename(char *path);
char get_filetype_char(mode_t mode);
char *merge_str(const char *stra, const char *strb);
char *my_strdup(char const *src);

int get_argument(config_t *config, int argc, char **argv);

void destroy_config(config_t *config);
void destroy_file_array(file_t *files, int size);

int filelist_push(files_name_t *list, char *path);
int filelist_destroy(files_name_t *list, int free_path);
char *filelist_getnext_path(files_name_t *list);
int count_notempty_node(files_name_t *list);

#endif
