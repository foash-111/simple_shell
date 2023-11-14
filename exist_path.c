#include"main.h"


/**
 * _getenv - find the path or any value of the variable name passed
 * @name: the variable name passed
 * Return: pointer to the first char of the value
*/
char *_getenv(const char *name)
{
	char **env = environ;
	int len = strlen(name);
	int i = 0;

	while (env[i])
	{
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (env[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}

/**
 * complete_path - check_command_if_exist_return_path
 * @command: command
 * Return: if the command passed is existed return it
 *  if the command without path return it with path
 * if it isn't a command return NULL
*/
char *complete_path(char *command)
{
	char *path;
	char *token, *complete_path, *fixed_path;
	char *copied_path, *check_command;

	if ((access(command, X_OK) == 0))
		return (strdup(command));

	check_command = strdup(command);
	free(check_command);

	path = _getenv("PATH");
	if (command == NULL || path == NULL)
	return (NULL);

	copied_path = strdup(path);

	token = strtok(copied_path, ":");
	while (token)
	{
		fixed_path = str_concat(token, "/");
		complete_path =  str_concat(fixed_path, command);
		free(fixed_path);

		if (access(complete_path, X_OK) == 0)
		{
		free(copied_path);
		return (complete_path);
		}
		else
			{
				free(complete_path);
				complete_path = NULL;
			}
			token = strtok(NULL, ":");
	}

free(copied_path);
return (NULL);
}
