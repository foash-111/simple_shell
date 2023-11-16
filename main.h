#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include <sys/wait.h>
#include<stdbool.h>
void interactive_mode(char **argv, char **env);
void non_interactive_mode(char **argv, char **env);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strdup(char *str);
int _atoi(char *s);

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
void exit_error_message(char **arr, char **argv, char *arr1);
void print_number(int n);

int comma(char *str, char **argv, char **env);

int env_command(char **arr, char **env);

int exit_command(char **arr, char **argv);

#endif
