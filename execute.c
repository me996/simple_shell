#include "shell.h"
/**
 * _execute - execute command from the user.
 * @command: An array of strings.
 * @argv: An array of strings representing the program's arguments.
 * 
 * Return: The exit status of the executed command.
*/
int _execute(char **command, char **argv)
{
pid_t child;
int status;

child = fork();
if (child == 0)
{
if (execve(command[0], command, environ) == -1)
{
perror(argv[0]);
freeleak(command);
exit(0);
}
}
else 
{
waitpid(child, &status, 0);
freeleak(command);
}
return(WEXITSTATUS(status));
}

