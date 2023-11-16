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
 * Return: value that will pSSED TO EXIT
*/
int eljoker(char *str, char **argv, char **env)
{
	char **arr = tokanized_array(str), *command_with_path;
	pid_t pid = 0;
	int status = 0, child_status;

if (arr[0] != NULL)
{
	status = exit_command(arr);
	if (status >= 0)
	return (status);
	if (env_command(arr, env) == 0)
	return (0);
	else if (check_exit_env(arr, str) == 2)
	return (2);
	command_with_path = complete_path(arr[0]);
	if (command_with_path == NULL)
	{
	error_message(arr, argv), free_all_array(arr);
	return (127); }
	else
	{
		free(arr[0]);
		arr[0] = _strdup(command_with_path);
		pid = fork();
		if (pid == 0)
		{
			if (execve(arr[0], arr, env) == -1)
			{
				exit(EXIT_FAILURE); } }
		else
		{
			 wait(&child_status);
		if (WIFEXITED(child_status) && WEXITSTATUS(child_status) != 0)
		{
			free_all_array(arr), free(command_with_path);
			return (WEXITSTATUS(child_status)); }
			free_all_array(arr); }
	free(command_with_path); } }
	else
	free_all_array(arr);
	return (0); }
