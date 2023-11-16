#include "main.h"

/**
 * _strlen - return the length of the string
 *
 * @s: the first parameter
 *
 * Return: int
*/

int _strlen(const char *s)
{
int count;

count = 0;

while (s[count])
{
count++;
}
if (s == NULL)
	return (0);
	else
return (count);
}

/**
* _strcmp - compare two strings with each other
*@s1: pointer to the base string
* @s2: pointer to the string i want to concat it
* Return: s1 > s2 ? 1 , s1 < s2 ? -1 : 0
*/

int _strcmp(char *s1, char *s2)
{
	int len1 = 0, len2 = 0, i = 0, max = 0, dif = 0;

while (s1[len1])
{
len1++;
}
while (s2[len2])
{
len2++;
}
if (len1 >= len2)
{
max = len1;
}
else
{
max = len2;
}
while (i < max)
{
if (s1[i] == s2[i])
{
i++;
}
else
{
dif = s1[i] - s2[i];
break;
}
}
return (dif);

}

/**
* _strncmp - compare two strings with each other
* @s1: pointer to the base string
* @s2: pointer to the string i want to concat it
* @n: nums of chars that we will compare
* Return: s1 > s2 ? 1 , s1 < s2 ? -1 : 0
*/
int _strncmp(const char *s1, const char *s2, int n)
{
int len1 = 0, len2 = 0, i = 0, min = 0, dif = 0;

while (s1[len1])
{
len1++;
}
while (s2[len2])
{
len2++;
}
if (len1 <= len2)
{
min = len1;
}
else
{
min = len2;
}
while (i < min && i < n)
{
if (s1[i] == s2[i])
{
i++;
}
else
{
dif = s1[i] - s2[i];
return (dif);
}
}
return (0);
}


/**
* _strdup - duplicate
* @str: string we want to dublicate
* Return: pointer to dublicated string
*/

char *_strdup(char *str)
{
	char *ptr;
	int len = 0, i = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	ptr = malloc((sizeof(char) * len) + 1);

	if (ptr == NULL)
		return (NULL);

	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';

	return (ptr);
}

/**
* _atoi - convert string to integer
*
* @s: pointer to the string that i want
* to convert
*
* Return: the integer value of the number
* that was in the string
*
*
*/


int _atoi(char *s)
{
	int i = 0;
	bool flag = 0;
	unsigned int x = 0;

	while (s[i])
	{
		if (s[i] == '-')
			flag = !flag;

		if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				x = ((int)s[i] - 48) + (x * 10);
				i++;
			}
			break;
		}
		i++;
	}

	if (flag)
		x = -x;

	return (x);
}
