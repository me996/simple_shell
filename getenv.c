#include "shell.h"

/**
 * _getenv - retrieves the value of an environment variable
 *
 * @var: A null-terminated string
 *
 * Return: A pointer to a string storing
 */

char *_getenv(char *var)
{
char *cp, *key, *val, *tmp;
int i;
for (i = 0; environ[i]; i++)
{
cp = _strdup(environ[i]);
key = strtok(cp, "=");
if (_strcmp(key, var) == 0)
{
val = strtok(NULL, "\n");
tmp = _strdup(val);
free(cp), cp = NULL;
return (tmp);
}
free(cp), cp = NULL;
}
return (NULL);
}


