#include "shell.h"
/**
 * readcmd - read command from the stdin
 * return: A pointer to a dynamically allocated string containing the user input if getline succeeds.
NULL if getline encounters an error or if the input is empty.
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
