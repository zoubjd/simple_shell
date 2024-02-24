#include "shell.h"

/**
 * my_execute - check the code
 * description: the function executes the commands
 * @command: the command to be executed
 * @argv: the command line arguments
 * @dex: the status
 * Return: Always 0.
 */

int my_execute(char **command, char **argv, __attribute__ ((unused)) int dex)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	if (command == NULL || command[0] == NULL)
	{
		return (0);
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (child_pid == 0)
	{
		execve(command[0], command, env);
		perror(argv[0]);
		free(command);
		_exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		return (WEXITSTATUS(status));
	}
}
