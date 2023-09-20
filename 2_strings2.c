#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * _strrchr - Finds the last occurrence of a character in a string.
 * @str: The string to be searched.
 * @ch: The character to be found.
 *
 * Return: A pointer to the last occurrence of the character
 */

char *_strrchr(const char *str, int ch)
{
char *last = NULL;
while (*str != '\0')
{
if (*str == ch)
{
last = (char *) str;
}
str++;
}
if (*str == ch)
{
last = (char *) str;
}
return (last);
}

/**
 * _basename - Returns the last component of a pathname.
 * @path: The path name to be parsed.
 *
 * Return: A pointer to the last component of the path name.
 */

char *_basename(char *path)
{
char *bsnm;
if (path == NULL)
{
return (NULL);
}
bsnm = _strrchr(path, '/');
if (bsnm == NULL)
{
return ((char *) path);
}
else
{
return (bsnm + 1);
}
}

/**
 * _strdup - Duplicates a string.
 * @src: The string to be duplicated.
 *
 * Return: A pointer to the newly allocated duplicate string.
 */

char *_strdup(char *src)
{
size_t len = strlen(src) + 1;
char *dst = malloc(len);
if (dst == NULL)
{
return (NULL);
}
_strcpy(dst, src);
return (dst);
}

/**
 * _strlen - Calculates the length of a string.
 * @str: The string whose length is to be determined.
 *
 * Return: The length of the string.
 */

int _strlen(char *str)
{
int length = 0;
while (*str != '\0')
{
length++;
str++;
}
return (length);
}

/**
 * _atoi - convert a string to an integer
 * @str: the string to convert
 *
 * Return: the integer value of the string, or 0 if no valid digits were found
 */

int _atoi(const char *str)
{
int result = 0;
int sign = 1;
while (*str == ' ' || *str == '\t' || *str == '\n')
str++;
if (*str == '-')
{
sign = -1;
str++;
}
else if (*str == '+')
{
str++;
}
while (*str >= '0' && *str <= '9')
{
result = result * 10 + (*str - '0');
str++;
}
return (result *sign);
}

