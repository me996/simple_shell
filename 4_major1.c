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
 * processInput - Reads user input, processes commands, and executes them.
 * @argc: no. of inputs
 *@argv: string array inputs
 */
void processInput(int argc, char **argv)
{
int n = 0, i;
char *args[arr_len] = {NULL}, *command = NULL;
while (1)
{
printf(":) ");
fflush(stdout);
if (n > 0 || (argc == 1 && argv != NULL))
{
fillCommand(&command); /* get command filled */
fillArgs(command, args); /* get args filled */
}
else if (argc > 1)
{/* get args second option*/
fillArgs2(argv, args);
n  = 1;
}
if (args[0] != NULL)
{
if (_strcmp(args[0], "exit") == 0)
{/* built in commands */
handleExit(args);
break;
}
else if (_strcmp(args[0], "env") == 0)
{
handleEnv();
}
else
{
handleAccess(args); /* child and parent processes */
}
/*free(command);*/
}
}
if (command != NULL)
{
free(command), command = NULL;
}
for (i = 0; i < arr_len; i++)
{
if (args[i] != NULL)
{
free(args[i]), args[i] = NULL;
}
}
}

/**
 * fillCommand - bring back the dynamic string
 * @command: pointer to a pointer to a NULL-terminated string
*/

void fillCommand(char **command)
{
ssize_t nread;
size_t command_size = 0;

nread = _getline(command, &command_size, stdin);
if (nread == -1)
{
printf("\n");
free(*command);
*command = NULL;
exit(EXIT_SUCCESS);
}
if (nread > 0 && (*command)[nread - 1] == '\n')
{
(*command)[nread - 1] = '\0';
}
free(*command), *command = NULL;
}

/**
 * fillArgs2 - Copies elements from argv to args
 * @argv: array of main()
 * @args: store the copied arguments
 */

void fillArgs2(char **argv, char **args)
{
int i, j = 1;
for (i = 0; argv[j] != NULL; i++, j++)
{
args[i] = argv[j];
}
args[i] = NULL;
}