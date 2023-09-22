#include "shell.h"

/**
 * readcmd - read command from the stdin
 *
 * Return: A pointer to a dynamically allocated string
 *
 */
char *readcmd(void)
{
char *cmd = NULL;
size_t len = 0;
ssize_t nread;
if (isatty(STDIN_FILENO))
write(STDIN_FILENO, "$ ", 2);
nread = getline(&cmd, &len, stdin);
if (nread == -1)
{
free(cmd), cmd = NULL;
return (NULL);
}
return (cmd);
}

