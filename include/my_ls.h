/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2020
** File description:
** my ls header
*/

#ifndef H_MYLS
#define H_MYLS

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <pwd.h>
#include <dirent.h>
#include "my.h"

#define EXIT_ERROR 84

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

int my_ls(int argc, char **argv);

int starting_browse(config_t *config);
int browse_folder(config_t *config, const char *pathdir);

int sort_files(file_t *files, int size, config_t *config);

int display_files_data(file_t *file, int size, config_t *config);
void display_type_and_right(file_t *file);
void display_owner(uid_t uid, gid_t gid);
void display_size(file_t *file);
void dipslay_lastmod_time(file_t *file);

int get_files_data(files_name_t *path, file_t **files,
config_t *config);
int get_files_name(config_t *config, DIR *dir);

int search_char_in_str(const char *str, char c);
int is_hidden_file(char *file_name);

int get_argument(config_t *config, int argc, char **argv);
void destroy_config(config_t *config);

int filelist_push(files_name_t *list, char *path);
int filelist_destroy(files_name_t *list, int free_path);
char *filelist_getnext_path(files_name_t *list);
int count_notempty_node(files_name_t *list);

#endif
