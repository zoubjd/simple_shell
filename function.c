#include "shell.h"

/**
 * executefree - Execute a command free the current
 * @arg: command to free
 */
void executefree(char **arg)
{
	int i = 0;

	if (arg == NULL)
		return;

	while (arg[i] != NULL)
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
/**
 * _itoa - Convert an integer to a string.
 * @n: The integer to convert.
 * Return: A pointer to a new string.
*/
char *_itoa(int n)
{
	char buf[15];
	int i = 0;

	if (n == 0)
	{
		buf[i++] = '0';
	}
	else
	{
		while (n != 0)
		{
			buf[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buf[i] = '\0';

	reverse_string(buf, i);
	return (_strdup(buf));
}
/**
 * reverse_string - Reverse a string.
 * @buf: The string to reverse.
 * @len: The length of the string.
*/
void reverse_string(char *buf, int len)
{
	char tmp;
	int start = 0, end = len - 1;

	while (start < end)
	{
		tmp = buf[start];
		buf[start] = buf[end];
		buf[end] = tmp;
		start++;
		end--;
	}
}
/**
 * print_error - Print an error message.
 * @name: The name of the program.
 * @command: The command that failed.
 * @index: The index of the command that failed.
*/
void print_error(char *name, char *command, int index)
{
	char *i = _itoa(index), message[] = ": not found\n";

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, _strlen(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, message, _strlen(message));

	free(i);
}
