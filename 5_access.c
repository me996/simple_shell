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
 * handleAccess - Locates the executable file
 * @args: An array of command arguments.
 */

void handleAccess(char **args)
{
int ac;
char *static_path, *loc, *dyn_path, file_path[arr_len], *mvptr = NULL;
static_path = getenv("PATH");
if (static_path != NULL)
{
dyn_path = _strdup(static_path);
loc = _strtok(dyn_path, ":", &mvptr);
while (loc != NULL)
{
_strcpy(file_path, loc);
_strcat(file_path, "/");
_strcat(file_path, _basename(args[0]));
ac = access(file_path, X_OK);
if (ac == 0)
{
args[0] = _basename(args[0]);
executeCommand(file_path, args);
free(dyn_path);
return;
}
loc = _strtok(NULL, ":", &mvptr);
}
free(dyn_path);
handleCommandNotFound(args);
}
}

/**
 * executeCommand - Executes the command as a child process
 * @file_path: Path to the executable file for the command.
 * @args: An array of command arguments.
 */

void executeCommand(char *file_path, char **args)
{
int status;
pid_t pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{ /* child process */
execve(file_path, args, environ);
}
else
{ /* parent process */
waitpid(pid, &status, 0);
}
}
