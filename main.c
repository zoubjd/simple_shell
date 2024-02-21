#include "shell.h"

int main(int argc __attribute__((unused)), char *argv[])
{
    char *line = NULL;
    char **command = NULL;
    int status = 0;

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            write(STDIN_FILENO, "$ ", 2);
        }

        line = read_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
            {
                write(STDOUT_FILENO, "\n", 1);
            }
            return (status);
        }
        else
        {
            command = tokens(line);
            status = my_execute(command, argv, status);
            if (command == NULL)
            {
                free(line);
                free(command);
            }
        }
    }
    return (0);
}
