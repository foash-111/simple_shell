#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include <sys/wait.h>
void interactive_mode(char **argv, char **env);
void non_interactive_mode(char **argv, char **env);


int _putchar(char c);
char *_getenv(const char *name);
char *complete_path(char *command);
char *str_concat(char *s1, char *s2);
char **tokanized_array(char *str);
int eljoker(char *str, char **argv, char **env);
int check_exit_env(char **arr, char *str);
void free_all_array(char **arr);


extern char **environ;

void error_message(char **arr, char **argv);
int env_command(char **arr, char **env);

int exit_command(char **arr);

#endif
