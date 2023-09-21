#include "shell.h"
/**
 * readcmd - read command from the stdin
 * @len: address of len var
 * @cmd: address of command line
 * @nread: cout the number of cmd read
 * return: NULL if an error occurs or if the input is empty.
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
return(NULL);
}
return(cmd);
}
