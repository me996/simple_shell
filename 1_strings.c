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
21:38
second file: 2_getline.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * _fgetc - Reads and returns a single character from a file.
 * @stream: A pointer to the FILE structure
 *
 * Return: The next character from the file
 */

int _fgetc(FILE *stream)
{
static char buf[BUFSIZ];
static char *bufp = buf;
static size_t n;
/*FILE *stream*/

if (n == 0)
{
n = read(fileno(stream), buf, sizeof(buf));
bufp = buf;
if (n <= 0)
{
return (EOF);
}
}
if (n > 0)
{
--n;
return ((unsigned char) *bufp++);
}
return (EOF);
}

/**
 * _memcpy - Copies memory from one location to another.
 * @dest: The destination pointer.
 * @src: The source pointer.
 * @n: The number of bytes to be copied.
 *
 * Return: A pointer to the destination memory area.
 */

void *_memcpy(void *dest, void *src, size_t n)
{
size_t i;
char *dest_ptr = (char *) dest;
char *src_ptr = (char *) src;
for (i = 0; i < n; i++)
{
*(dest_ptr + i) = *(src_ptr + i);
}
return (dest);
}

/**
 * _realloc - Reallocates a block of memory
 * @ptr: A pointer to the block of memory to be reallocated.
 * @size: The new size of the block of memory.
 *
 * Return: A pointer to the reallocated memory block on success
 */

void *_realloc(void *ptr, size_t size)
{
void *newptr;
if (size == 0)
{
free(ptr);
return (NULL);
}
newptr = malloc(size);
if (newptr == NULL)
{
return (NULL);
}
if (ptr != NULL)
{
_memcpy(newptr, ptr, size);
free(ptr);
}
return (newptr);
}

/**
 * _getline - Reads a line of input from a specified file stream.
 * @lineptr: A pointer to a char pointer
 * @n: A pointer to the size of the buffer.
 * @stream: A pointer to the FILE structure
 *
 * Return: The number of characters read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
char *buf = NULL;
int c = EOF;
size_t i = 0;
if (lineptr == NULL || n == NULL)
{
errno = EINVAL;
return (-1);
}
if (*lineptr == NULL)
{
*n = 256;
*lineptr = malloc(*n);
if (*lineptr == NULL)
{
errno = ENOMEM;
return (-1);
}
}
buf = *lineptr;
/*------  stream ------*/
while ((c = _fgetc(stream)) != '\n' && c != EOF)
{
if (i + 1 >= *n)
{
*n += 256;
*lineptr = _realloc(*lineptr, *n);
if (*lineptr == NULL)
{
errno = ENOMEM;
return (-1);
}
buf = *lineptr + i;
}
*buf++ = c;
++i;
}
*buf = '\0';
return (i ? i : EOF);
}
