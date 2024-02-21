#include "shell.h"

char *_strdup(const char *str)
{
        char *pointer;
        int i = 0, len;

        if (str == NULL)
        {
                return (NULL);
        }

        len = strlen(str);

        pointer = malloc(len + 1);
        if (pointer == NULL)
        {
                return (NULL);
        }
        while (str[i] != '\0')
        {
                pointer[i] = str[i];
                i++;
        }
        pointer[len] = '\0';
        return (pointer);
}

char _strcmp(const char *str1, const char *str2)
{
        int i = 0;

        while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
                i++;

        return (int)str1[i] - (int)(str2[i]);
}

int _strlen(const char *s)
{
        int len;

        for (len = 0; s[len] != '\0'; len++)
        {
        }

        return (len);
}

char *_strcat(char *d, const char *src)
{
        size_t len = strlen(d);
        size_t i;

        for (i = 0; src[i] != '\0'; i++)
        {
                d[len + i] = src[i];
        }

        d[len + i] = '\0';

        return (d);
}

char *_strcpy(char *d, const char *src)
{
        int i;

        for (i = 0; src[i] != '\0'; i++)
        {
                d[i] = src[i];
        }

        d[i] = '\0';

        return (d);
}
