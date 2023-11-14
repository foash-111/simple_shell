#include"main.h"
/**
 * interactive_mode - read from user in active mode
 * @argv:  array of pointers to the arguments
 * @env: array of pointers to the environment variables
 * Retuen: nothing
*/


void interactive_mode(char **argv, char **env)
{
	size_t in_len = 0;
	char *str;
	int reads_chars;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);

	   reads_chars = getline(&str, &in_len, stdin);

		if (reads_chars == -1)
		{
		free(str);
		exit(EXIT_SUCCESS);
		}
			str[reads_chars - 1] = '\0';

			eljoker(str, argv, env);
			free(str);
	}

}

/**
 * non_interactive_mode - read from file or ready input
 * @argv:  array of pointers to the arguments
 * @env: array of pointers to the environment variables
 * Retuen: nothing
*/
void non_interactive_mode(char **argv, char **env)
{
	size_t in_len = 0;
	char *str;
	int reads_chars;
while (1)
{
	reads_chars = getline(&str, &in_len, stdin);

	if (reads_chars == -1)
	{
		free(str);
		return;
	}

if (str[0] == '\n')
continue;

	if (str[reads_chars - 1] == '\n')
	str[reads_chars - 1] = '\0';

	eljoker(str, argv, env);
	free(str);
}


}

/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument vectors
 * @env: environments variables
 * Return: 0 on success
*/
int main(int argc, char **argv, char **env)
{
(void)argc;

	if (isatty(STDIN_FILENO) == 1)
	{
	interactive_mode(argv, env);
	}
	else
	{
	non_interactive_mode(argv, env);
	}


	return (0);
}
