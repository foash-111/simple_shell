#include"main.h"

/**
 * eljoker - it's do any thing it's the JOKER
 * there are inside it:
 * tokanize
 * complete path
 * execute command
 * @str: string we read
 * @argv:  array of pointers to the arguments
 * @env: array of pointers to the environment variables
 * Retuen: nothing
*/
void eljoker(char *str, char **argv, char **env)
{
	char **arr = tokanized_array(str);
	char *command_with_path;
	pid_t pid = 0;

if (arr[0] != NULL)
{
	if (exit_command(str) || env_command(arr, env))
	return;
	check_exit_env(arr, str);

	command_with_path = complete_path(arr[0]);
	if (command_with_path == NULL)
	{
	error_message(arr, argv);
	free_all_array(arr);
	free(str);
	exit(127);
	}
	else
	{
		free(arr[0]);
		arr[0] = strdup(command_with_path);
		pid = fork();
		if (pid == 0)
		{
			if (execve(arr[0], arr, NULL) == -1)
			{
				error_message(arr, argv);
				free(str);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
			free_all_array(arr);
		}
	free(command_with_path);
	} } }
