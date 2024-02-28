#include "shell.h"

char *make_env(char *path)
{
    char *p, *value, *last, *key;
    int i = 0;

    while (environ[i] != NULL)
    {
        p = _strdup(environ[i]);
        last = strtok(p, "=");
        if (_strcmp(last, path) == 0)
        {
            value = strtok(NULL, "\n");
            key = _strdup(value);
            free(p);
            return (key);
        }
        free(p);
        i++;
    }
    return (NULL);
}

char *make_path(char *path)
{
    char *pe = make_env("PATH"), *fullcmd = NULL, *storage;
    int i = 0;
    struct stat st;

    if (pe == NULL)
	    return (NULL);

    while (path[i] != '\0')
    {
    if (path[i] == '/')
    {
    if (stat(path, &st) == 0)
    {
    free(pe);
    return (_strdup(path));
    }
    else
    {
	free(pe);
        return (NULL);
    }
    }
    i++;
    }

    storage = strtok(pe, ":");
    while (storage != NULL)
    {
        fullcmd = malloc(_strlen(path) + _strlen(storage) + 2);
        if (fullcmd != NULL)
        {
            _strcpy(fullcmd, storage);
            _strcat(fullcmd, "/");
            _strcat(fullcmd, path);
            if (stat(fullcmd, &st) == 0)
            {
		free(pe);
                return (fullcmd);
            }
            else
            {
                free(fullcmd);
            }
            storage = strtok(NULL, ":");
        }
    }
    free(pe);
    return (NULL);
}

