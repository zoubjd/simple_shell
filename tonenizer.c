#include "shell.h"

char **tokens(char *line)
{
    char *token = NULL, *delim = " \t\n";
    char **command = NULL, *ptr = line;
    int num_tokens = 1;
    int i = 0;

    if (line == NULL)
    {
        return NULL;
    }

    while (*ptr != '\0')
    {
        if (strchr(delim, *ptr) != NULL)
        {
            num_tokens++;
        }
        ptr++;
    }

    command = malloc((num_tokens + 1) * sizeof(char *));
    if (command == NULL)
    {
        free(line);
        return NULL;
    }

    token = strtok(line, delim);
    if (token == NULL)
    {
        free(line);
        free(command);
        return (NULL); /* no command entered */
    }
    command[0] = _strdup(token);
    if (command[0] == NULL)
    {
        free(line);
        free(command);
        return (NULL);
    }

    for (i = 1; i < num_tokens; i++)
    {
        command[i] = NULL; /* initialize all other tokens to NULL*/
    }
    command[num_tokens] = NULL;

    free(line);
    return command;
}
