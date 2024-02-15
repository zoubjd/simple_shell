#include "shell.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>

int main(int argc, char *argv[])
{
    char *line = NULL;
    char **com = NULL;
    int stts = 0, commandindex = 0;
    char newline = '\n';
    char error_message[] = ": command not found\n";
    (void)argc;

    while (1)
    {
        line = readLine();
        if (line == NULL)
        {
            if (isatty(STDOUT_FILENO))
            {
                write(STDOUT_FILENO, &newline, 1);
            }
            return (stts);
        }
        commandindex++;
        com = parser(line);
        if (com == NULL)
        {
            continue;
        }
        if (check_builtin(com[0]))
        {
            handle_builtin(com, argv, &stts, commandindex);
        }
        else
        {
            write(STDERR_FILENO, com[0], strlen(com[0]));
            write(STDERR_FILENO, error_message, strlen(error_message));
            stts = 127;
        }
    }
    return (0);
}