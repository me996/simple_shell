#include "shell.h"

/**
 * positive_num - checks if a string is a positive integer
 *
 * @s: A pointer to a string to check
 *
 * Return: 1 if the string is a positive integer, 0 otherwise
 */

int positive_num(char *s)
{
int i;
if (s == NULL)
return (0);
for (i = 0; s[i]; i++)
{
if (s[i] < '0' || s[i] > '9')
return (0);
}
return (1);
}

/**
 * _atoi - converts a string of digits to an integer
 *
 * @s: A pointer to a null-terminated string to convert
 *
 * Return: The converted integer value of the string
 */

int _atoi(char *s)
{
int i, number = 0;
for (i = 0; s[i]; i++)
{
number *= 10;
number += (s[i] - '0');
}
return (number);
}


