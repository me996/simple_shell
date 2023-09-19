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
