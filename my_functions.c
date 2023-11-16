#include"main.h"

/**
 * exit_error_message - print error message with write
 * because it's said printf isn't allowed
 * @arr: array of pointers to the commands
 * @argv:  array of pointers to the arguments
 * Retuen: nothing
*/
void exit_error_message(char **arr, char **argv)
{

	char *error_message, *first_part, *second_part;

	first_part = str_concat(argv[0], ": 1: ");
	second_part = str_concat(first_part, arr[0]);
	error_message = str_concat(second_part, ": Illegal number: ");
	write(STDERR_FILENO, error_message, _strlen(error_message));

	free(first_part);
	free(second_part);
	free(error_message);

}


/**
 * print_number - print number.
 *@n: the number we want to print
 * Return: void.
 */

void print_number(int n)
{
	unsigned int temp = 0, count = 0;

	if (n == 0)
{

	_putchar('0');
}

else
{
	if (n < 0)
	{
		_putchar('-');
		n = -1 * n;
	}

	while (n)
	{
		/*987*/
		/*7//70 + 8 == 78//780 + 9 == 789*/

		temp = (n % 10) + (temp * 10);

		/*temp *= 10;//70//780//7890 --error--*/

		n = n / 10;
		count++;
	}

	while (count--)/*987*/
	{
		/*/7//8//9*/
		_putchar('0' + temp % 10);
		/*98////9//0*/
		temp /= 10;

	}

}
}
