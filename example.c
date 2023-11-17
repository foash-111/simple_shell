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
char *str = NULL;
int reads_chars, status = 0, temp = 0, i = 0, flag = 0;

while (1)
{
write(STDOUT_FILENO, "($) ", 4);
reads_chars = getline(&str, &in_len, stdin);
if (reads_chars == -1)
{ break; }
str[reads_chars - 1] = '\0';
if (str[0] == '\0')
{
free(str);
str = NULL;
continue; }
if (str != NULL)
while (str[i])
{
if (str[i] == ';')
{ flag = 1; }
if (str[0] == '#' || (str[i] == '#' && str[i - 1] == ' '))
{
str[i] = ' ';
if (str[i + 1] != '\0')
str[i + 1] = '#'; }
i++; }
i = 0;
if (flag == 1)
{ status = comma(str, argv, env); }
else
{ status = eljoker(str, argv, env); }
if (_strncmp(str, "exit", 4) == 0)
{ free(str), str = NULL;
exit(temp); }
free(str);
str = NULL;
temp = status; }
if (str)
free(str);
exit(status); }

/**
 * non_interactive_mode - read from file or ready input
 * @argv:  array of pointers to the arguments
 * @env: array of pointers to the environment variables
 * Retuen: nothing
*/
void non_interactive_mode(char **argv, char **env)
{
size_t in_len = 0;
char *str = NULL;
int reads_chars, status = 0, temp = 0, i = 0, flag = 0;
while (1)
{
reads_chars = getline(&str, &in_len, stdin);
if (reads_chars == -1)
{
free(str);
break; }
if (str[reads_chars - 1] == '\n')
str[reads_chars - 1] = '\0';
if (str[0] == '\0')
{
str = NULL;
	continue; }
while (str[i])
{
if (str[i] == ';')
flag = 1;
if (str[0] == '#' || (str[i] == '#' && str[i - 1] == ' '))
{
str[i] = ' ';
if (str[i + 1] != '\0')
str[i + 1] = '#'; }
i++; }
i = 0;
if (flag == 1)
{ status = comma(str, argv, env); }
else
{ status = eljoker(str, argv, env); }
if (_strncmp(str, "exit", 4) == 0)
{
free(str);
str = NULL;
exit(temp);
}

temp = status;  }
exit(status);
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
