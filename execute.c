#include "shell.h"
/**
 * _execute - execute command from the user.
 * @command: An array of strings.
 * @argv: An array of strings representing the program's arguments.
 * @cpt: The command's execution count.
 *
 * Return: The exit status of the executed command.
*/
int _execute(char **command, char **argv, int cpt)
{
char *command_env;
pid_t child;
int status;
command_env = _getpath(command[0]);
if (!command_env)
{
printerror(argv[0], command[0], cpt);
freeleak(command);
return (127);
}
child = fork();
if (child == 0)
{
if (execve(command_env, command, environ) == -1)
{
free(command_env), command_env = NULL;
freeleak(command);
}
}
else
{
waitpid(child, &status, 0);
freeleak(command);
free(command_env), command_env = NULL;
}
return (WEXITSTATUS(status));
}

