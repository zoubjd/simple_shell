#include "shell.h"

char *_make_env(char *path)
{
    char *env, *key, *value, *retvalue;
int i;

for(i = 0; environ[i]; i++)
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
    free(env);
}
return (NULL);
}

char *_make_path(char *command)
{
    char *path, *fullcmd, *dir;
    struct stat st;
    int i;

    for (i = 0; command[i]; i++)
    {
        if (command[i] == '/')
        {
            if (stat(command, &st) == 0)
                return (_strdup(command));

            return (NULL); 
        }
    }
    path = _make_env("PATH");
    if(path == NULL)
        return (NULL);

    dir = strtok(path, ":");
    while(dir)
    {
        fullcmd = malloc(_strlen(dir) + _strlen(command) + 2);
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
 
