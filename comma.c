#include"main.h"

/**
 * comma - execute line with commas
 * @str: the read line passed
 * @argv: arguments vectors
 * @env: environment variables
 * Return: status
*/
int comma(char *str, char **argv, char **env)
{
int status = 0;
	char **arr;
	char *dub, *ptr;
	int i = 0;

	dub = _strdup(str);
	ptr = strtok(str, ";");
	while (ptr != NULL)
	{
		ptr = strtok(NULL, ";");
		i++;
	}
arr = malloc(sizeof(char *) * (i + 1));
if (arr == NULL)
{
	perror("Error: Could not allocate memory.\n");
	free(dub);
	exit(EXIT_FAILURE);
}
i = 0;
ptr = strtok(dub, ";");
while (ptr)
{
	arr[i] = _strdup(ptr);
	ptr = strtok(NULL, ";");
	i++;
}
arr[i] = NULL;
i = 0;
while (arr[i])
{
status = eljoker(arr[i], argv, env);
i++;
}
free(dub);
free_all_array(arr);
return (status);
}
