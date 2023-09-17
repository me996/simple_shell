#include "shell.h"

char *_strdup(const char *s)
{
    char *ptr;
    int  i, len = 0;
    if (s == NULL)
    return(NULL);
    while (*s != '\0')
    {
        len++;
        s++;
    }
    s = s - len;
    ptr = malloc(sizeof(char) * (len + 1));
    if (ptr == NULL)
    return (NULL);
    for (i = 0; i <= len; i++)
    ptr[i] = s[i];
    return (ptr);
}
int _strcmp(char *s1, char *s2)
{
    int cmp;
    cmp = (int)*s1 - (int)*s2;
    while (*s1)
    {
        if (*s1 != *s2)
        break;
        s1++;
        s2++;
        cmp = (int)*s1 - (int)*s2;
    }
    return (cmp);
}
int _strlen (char *s)
{
    int len = 0;
    while (s[len])
    len++;
    return(len);
}
char *_strcat(char *dest, char *src)
{
    char *p = dest;
    while(*p)
    p++;
    while (*src)
    {
        *p = *src;
        p++;
        src++;
    }
    *p = *src;
    return(dest);
}
char *_strpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
}
