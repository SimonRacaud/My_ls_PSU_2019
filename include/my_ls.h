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
#include <dirent.h>
#include "my.h"

#define EXIT_ERROR 84

typedef struct config {
    char sort_mod_time_mode;
    char sort_reverse_mode;
    char list_mode;
    char directory_mode;
    char recusif_mode;
    unsigned int nb_path;
    char **path;
} config_t;

typedef struct file {
    char *name;
    mode_t mode;
    nlink_t link;
    ino_t inode;
    uid_t uid;
    gid_t gid;
    off_t size;
    time_t last_mod;
    unsigned int minor;
    unsigned int major;
    struct file *next;
} file_t;

int browse_folders(config_t *config);
int browse_folder(config_t *config, const char *folder);

int display_files_data(file_t *file);

void sort_path(config_t *config);

int get_files_data(config_t *config);
int get_files_name(config_t *config, DIR *dir);

int search_char_in_str(const char *str, char c);
int is_hidden_file(char *file_name);

int get_argument(config_t *config, int argc, char **argv);
void destroy_config(config_t *config);

#endif
