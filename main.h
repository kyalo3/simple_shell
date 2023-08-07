#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>

#define BUF_SIZE 1024
#define TOK_BUFSIZE 128
#define MAX_PROMPT 100
#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 64

extern char **environ; /* Declare environ*/
extern int errno;
char *my_getline(void);
/*void split(const char *command, char **argv);*/
/*void execute_command(char *command, char **args);*/

int execute_builtin(char **args);
void handle_path(char **args);
void handle_env(void);
void handle_exit(void);

/*char **env;*/
extern char **environ;
/*int arg_count;*/
int prom_dis(void);
void exec_command(char *command);
int read_command(char *command);
void display_prompt(void);
int split(char *command, char *string[]);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/*int arg_v(int argc, char *argv[])*/
int main(void);

#endif
