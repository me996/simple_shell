#include "shell.h"


/**
 * printerror - outputs an error message to stderr
 * @name: A null-terminated string representing the name of the shell program
 * @cmd: A null-terminated string
 * @cpt: An integer representing the command's position in the command line
 */

void printerror(char *name, char *cmd, int cpt)
{
char *idx, message[] = ": not found\n";
idx = _itoa(cpt);
write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, idx, _strlen(idx));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, message, _strlen(message));
free(idx), idx = NULL;
}
/**
 * _itoa - Convert an integer to a string.
 * @s: The integer to convert.
 *
 * Return: A pointer to the converted string.
 */
char *_itoa(int s)
{
char buffer[10];
int i = 0;
if (s == 0)
buffer[i++] = '0';
else
{
while (s > 0)
{
buffer[i++] = (s % 10) + '0';
s /= 10;
}
}
buffer[i] = '\0';
reverse_string(buffer, i);
return (_strdup(buffer));
}

/**
 * reverse_string - reverses a string in place
 *
 * @s: A null-terminated string to reverse
 * @len: The length of the string
 */
void reverse_string(char *s, int len)
{
char cpy;
int begin = 0;
int last = len - 1;
while (begin < last)
{
cpy = s[begin];
s[begin] = s[last];
s[last] = cpy;
begin++;
last--;
}
}


