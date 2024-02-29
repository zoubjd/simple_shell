#include "shell.h"
/**
 * make_env - make a shell environment 
 * @path: path to search
 * Return: NULL.
 */
char *make_env(char *path)
{
    char *env, *key, *value, *retvalue;
    int i = 0;

while (environ[i] != NULL)
{
    env = _strdup(environ[i]);
    key = strtok(env, "=");
    if(_strcmp(key, path) == 0)
    {
        value = strtok(NULL, "\n");
        retvalue = _strdup(value);
        free(env);
        return (retvalue);
    }
    i++;
    free(env);
}
return (NULL);
}
/**
 * make_path - make a path for a command line argument
 * @command: command line argument.
 * Return: return full path or NULL if not found
 */
char *make_path(char *command)
{
    char *path, *fullcmd, *dir;
    struct stat st;
    int i = 0;

    while (command[i] != '\0')
    {
        if (command[i] == '/')
        {
            if (stat(command, &st) == 0)
                return (_strdup(command));
            else
                return (NULL);
        }
        i++;
    }
    path = make_env("PATH");
    if(path == NULL)
        return (NULL);

    dir = strtok(path, ":");
    while (dir)
    {
        fullcmd = malloc(_strlen(command) + _strlen(path) + 2);
        if (fullcmd)
        {
            _strcpy(fullcmd, dir);
            _strcat(fullcmd, "/");
            _strcat(fullcmd, command);
            if (stat(fullcmd, &st) == 0)
            {
                free(path);
                return(fullcmd);
            }
            free(fullcmd);
            dir = strtok(NULL, ":");
        }
    }
    free(path);
    return (NULL);
}
