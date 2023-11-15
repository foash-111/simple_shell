#include "main.h"

/**
 * exit_command - exit_command
 * @arr: array of arguments passed from tokanize
 * Return: exit statues or 0 in failure
*/
int exit_command(char *str)
{
	int i = 0;
	char **arr = tokanized_array(str);

	if (strcmp(arr[0], "exit") == 0)
{

	if (arr[1] != NULL)
	i = atoi(arr[1]);
free_all_array(arr);
free(str);
	exit(i);
}
free_all_array(arr);
return (0);
}

/**
 * env_command - env_command  prints the current environment
 * @arr: array of arguments passed from tokanize
 * @env: environment variables
 * Return: exit statues or 0 in failure
*/
int env_command(char **arr, char **env)
{
	 int i = 0;

if (strcmp(arr[0], "env") == 0)
{
	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		_putchar('\n');
		i++;
	}
free_all_array(arr);
return (1);
}
return (0);
}

/**
 * check_exit_env - check_exit_env
 * @arr: array of arguments passed from tokanize
 * Return: exit statues with 2 if we find env or exit with path
 * because they are bulit in command they have not a path
*/
void check_exit_env(char **arr, char *line)
{
	char *ptr, *str = strdup(arr[0]);
	int i = 0;

	ptr = strtok(str, "/");
	while (ptr != NULL)
	{
		if (strcmp(ptr, "exit") == 0 || strcmp(ptr, "env") == 0)
		{
		free(str);
		free_all_array(arr);
		free(line);
		exit(2);
		}
		ptr = strtok(NULL, "/");
		i++;
	}

free(str);
}

/**
 * error_message - print error message with write
 * because it's said printf isn't allowed
 * @arr: array of pointers to the commands
 * @argv:  array of pointers to the arguments
 * Retuen: nothing
*/
void error_message(char **arr, char **argv)
{

	char *error_message, *first_part, *second_part;

	first_part = str_concat(argv[0], ": 1: ");
	second_part = str_concat(first_part, arr[0]);
	error_message = str_concat(second_part, ": not found\n");
	write(STDERR_FILENO, error_message, strlen(error_message));

	free(first_part);
	free(second_part);
	free(error_message);

}

/**
 * free_all_array - free_all_array
 * @arr: array of pointers to the commands
 * Retuen: nothing
*/
void free_all_array(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	
	free(arr);
}
