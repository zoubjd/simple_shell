#include "shell.h"

int my_execute(char **command, __attribute__ ((unused)) char **argv,
__attribute__ ((unused)) int idex)
{
	pid_t child_pid;
	int status;

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
	execve(command[0], command, NULL);
	perror("execve");
	_exit(EXIT_FAILURE);
	}
	else
	{
	waitpid(child_pid, &status, 0);
	return (WEXITSTATUS(status));
	}
}
