#include "main.h"
#include <stdio.h>
#include <stddef.h>

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: An integer
 */
int _strcmp(char *s1, char *s2)
{
    if (s1 == NULL && s2 == NULL) 
    {
        return 0;  
        
    } else if (s1 == NULL) 
    {
        return -1;  
        
    } else if (s2 == NULL)
     {
        return 1;     
    }

    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}


/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
char *result;
if (dest == NULL || src == NULL)
{
return (NULL);
}
result = dest;
while ((*dest++ = *src++) != '\0')
;
return (result);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
char *result;
if (dest == NULL || src == NULL)
{
return (NULL);
}
result = dest;
while (*dest != '\0')
{
dest++;
}
while ((*dest++ = *src++) != '\0')
;
return (result);
}

/**
 * _strcspn - Calculates the length of the initial segment
 * @str: The string to be searched.
 * @set: The string containing the characters to be excluded.
 * Return: The length of the initial segment
 */
size_t _strcspn(char *str, char *set)
{
size_t i = 0, j = 0;
while (str[i])
{
if (set[j] == str[i])
{
break;
}
j++;
if (set[j] == '\0')
{
/*increased i only after looping all "set" letters*/
j = 0;
i++;
}
}
return (i);
}


/**
 * _strtok - Breaks a string into a sequence tokens.
 * @str: The string to be tokenized.
 * @delim: The string containing delimiter characters.
 * @mvptr: A pointer to a char pointer
 * Return: A pointer to the next token
 */

char *_strtok(char *str, char *delim, char **mvptr)
{
char *token;
char *p;
if (str != NULL)
{
*mvptr = str;
}
else if (*mvptr == NULL || **mvptr == '\0')
{
return (NULL);
}
token = *mvptr;
p = token + _strcspn(token, delim);
if (*p != '\0')
{
*p++ = '\0';
}
*mvptr = p;
return (token);
}
