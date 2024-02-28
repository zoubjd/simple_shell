#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;


char *read_line(void);

char **tokens(char *line);
void executefree(char **arg);

char *_strdup(const char *str);
char _strcmp(const char *str1, const char *str2);
int _strlen(const char *s);
char *_strcat(char *d, const char *src);
char *_strcpy(char *d, const char *src);
int _isdigit(int c);
int _atoi(char* str);
//int builtin_commands(char *command);
int handle_commands(char **command, int status);

int exit_shell(char **command ,int status);
void _print_env(char **command);

/*path*/
char *_make_env(char *path);
char *_make_path(char *command);

/*error*/
void print_error(char *name, char *command, int index);
void reverse_string(char *buf, int len);
char* _itoa(int n);
int my_execute(char **command, char **argv, int dex);

#endif
