#include "shell.h"
char *_strdup(const char *s)
{
    char *ptr;
    int, len = 0;
    if (str == NULL)
    return(NULL);
    while (*str != '0')
    {
        len++;
        str;
    }
    str = str - len;
    ptr = malloc(sizeof(char) * (len + 1));
    if (pttr == NULL)
    return (NULL);
    for (i = 0; i <= len; i++)
    ptr[i] = str[i];
    return (ptr);
}

