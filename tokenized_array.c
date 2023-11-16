#include"main.h"

/**
 * tokanized_array - tokanized_array
 * @str: string i want to tokanize
 * Return: tokanized_array
*/

char **tokanized_array(char *str)
{
	char **arr;
	char *dub, *ptr;
	int i = 0;

	 dub = _strdup(str);

	ptr = strtok(str, " \n\t");
	while (ptr != NULL)
	{
		ptr = strtok(NULL, " \n\t");
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
ptr = strtok(dub, " \n\t");
while (ptr)
{
	arr[i] = _strdup(ptr);
	ptr = strtok(NULL, " \n\t");
	i++;
}
arr[i] = NULL;
free(dub);
return (arr);
}
