#include "shell.h"
/**
 * my_execute - execute a command and return the exit status
 * @command: the command to be executed
 * @argv: the arguments of the command
 * @dex: the index of the command in the array
 * Return: the exit status of the command
*/
int my_execute(char **command, char **argv, int dex)
{
	pid_t child_pid;
	int status;
	char **env = environ;
	char *fullcmd;

	if (command == NULL || command[0] == NULL)
	{
		return (0);
	}
	fullcmd = make_path(command[0]);
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
			executefree(command);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
	waitpid(child_pid, &status, 0);
	executefree(command);
	free(fullcmd);
	}
	return (WEXITSTATUS(status));
}
/**
 * handle_commands - handle the commands of the shell
 * @command: the command to be executed
 * @status: the status of the command
 * @argv: the arguments to be passed to the command
 * @index: the index of the command
 * Return: Always 0.
*/
int handle_commands(char **command, int status, char **argv, int index)
{
	int result = 0;
	int new_status = 0;

	switch (_strcmp(command[0], "exit"))
	{
		case 0:
			if (command[1])
			{
			new_status = _atoi(command[1]);
			if (new_status < 0)
			{
			error_exit(argv[0], command, index);
			}
			else
			{
			exit_shell(command, new_status);
			}
			}
			exit_shell(command, status);
			result = 1;
			break;
		default:
			switch (_strcmp(command[0], "env"))
			{
				case 0:
					_print_env(command);
					result = 1;
					break;
				default:
					break;
			}
			break;
	}
	return (result);
}

/**
 * exit_shell - exit the shell program
 * @command: the command to be executed
 * @status: the status of the command
 * Return: Always 0.
*/
int exit_shell(char **command, int status)
{
	executefree(command);
	exit(status);
}
/**
 * _print_env - print the environment variables to stdout
 * @command: the command to be executed.
*/
void _print_env(char **command)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	executefree(command);
}

