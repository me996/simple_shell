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
 * fillArgs - Extracts words from the command and fills the args array.
 * @command: The input command string.
 * @args: An array to store the extracted words.
 */

void fillArgs(char *command, char **args)
{
char *mvptr = NULL;
char *token;
int i = 0;
token = _strtok(command, " ", &mvptr);
while (token != NULL && i < arr_len)
{
args[i++] = token;
token = _strtok(NULL, " ", &mvptr);
}
args[i] = NULL;
}

/**
 * handleExit - Handles the "exit"
 * @args: arguments array
 * return: nothing
 */

void handleExit(char **args)
{
int exitStatus = 0;
if (args[1] != NULL)
{
exitStatus = _atoi(args[1]);
}
exit(exitStatus);
}


/**
 * handleEnv - Handles the "env" command by printing the environment variables.
 */
void handleEnv(void)
{
char **env = environ;
while (*env != NULL)
{
if (write(STDOUT_FILENO, *env, _strlen(*env)) == -1)
{
perror("write");
exit(EXIT_FAILURE);
}
if (write(STDOUT_FILENO, "\n", 1) == -1)
{
perror("write");
exit(EXIT_FAILURE);
}
env++;
}
}



/**
 * handleCommandNotFound - Handles the case when a command is not found.
 * @args: An array of command arguments.
 */

void handleCommandNotFound(char **args)
{
int x, y, z, k, m;

k  = write(STDERR_FILENO, "hsh", 4);
m  = write(STDERR_FILENO, ": ", 3);
x =
write(STDERR_FILENO, args[0], strlen(args[0]));
y  = write(STDERR_FILENO, ": command not found", 19);
z = write(STDERR_FILENO, "\n", 1);
if (x < 0 || y < 0 || z < 0 || k < 0 || m < 0)
{
perror("write");
exit(EXIT_FAILURE);
}
}
