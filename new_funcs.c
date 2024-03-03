#include "shell.h"

/**
 * _atoi - turns a string into a number
 * @src: the source
 * Return: the number or -1.
*/

int _atoi(char *src)
{
int result = 0;
int sign = 1;
int i = 0;

if (src[i] == '-')
{
sign = -1;
i++;
}
while (src[i])
{
if (src[i] < '0' || src[i] > '9')
{
return (-1);
}
else
{
result = result * 10 + (src[i] - '0');
i++;
}
}
return (sign *result);
}

/**
 * error_exit - prints an error if exit is wrong
 * @name: the name of file
 * @command: the command
 * @index: the number of the current line
*/

int error_exit(char *name, char **command, int index)
{
char *i = _itoa(index), message[] = ": Illegal number: ";

write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, i, _strlen(i));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command[0], _strlen(command[0]));
write(STDERR_FILENO, message, _strlen(message));
write(STDERR_FILENO, command[1], _strlen(command[1]));
write(1, "\n", 1);
free(i);
executefree(command);
exit(2);
}

