#include "shell.h"

/**
 * my_execute - check the code
 * description: the function executes the commands
 * @command: the command to be executed
 * @argv: the command line arguments
 * @dex: the status
 * Return: Always 0.
 */

int my_execute(char **command, char **argv, int dex)
{
	pid_t child_pid;
	int status;
	char **env = environ;
	char *fullcmd;

	/*if (_strcmp(command[0], "exit") == 0)
	{
		executefree(command);
		exit(0);
	}*/

	
	fullcmd = _make_path(command[0]);
	if (fullcmd == NULL)
	{
		print_error(argv[0], command[0], dex);
		executefree(command);
		return (127);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(fullcmd, command, env) == -1)
		{
			free(fullcmd);
			fullcmd = NULL;
			executefree(command);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
	waitpid(child_pid, &status, 0);
	executefree(command);
	free(fullcmd);
	fullcmd = NULL;
	}

	return (WEXITSTATUS(status));
}

/*int builtin_commands(char *command)
{
	char *exi_command[] = {"exit", "env", NULL};
	int i = 0;
	while (command[i])
	{
		if (_strcmp(command, exi_command[i]))
			return (1);
	}
	return (0);
}
*/

int handle_commands(char **command, int status)
{
	if (_strcmp(command[0], "exit") == 0)
	{
	int new_status = 0;
	int i;
	for (i = 0; command[1][i]; i++)
	{
		if (_isdigit(command[1][i]) == 0)
		{
		exit_shell(command, status); 
		return (1);
		}
	}
	new_status = _atoi(command[1]);
	exit_shell(command, new_status); 
	return (1);
	}
	else if (_strcmp(command[0], "env") == 0)
		{
		_print_env(command);
		return (1);
		
		}

	else
		return (0);
}

int exit_shell(char **command ,int status)
{
	executefree(command);
	exit(status);
}

void _print_env(char **command)
{
int i = 0;
if (environ)
{
while(environ[i]) {
write(STDOUT_FILENO, environ[i], strlen(environ[i]));
write(1, "\n", 1);
i++;
}
}
else
	write(1, "\n", 1);
executefree(command);
}
