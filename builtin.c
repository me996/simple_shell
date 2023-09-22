#include "shell.h"
int built_in(char *input_cmd)
{
char *builtin_command[] = { "exit", "env", "setenv","unsetenv", "cd", NULL};
int i; 
for (i = 0; builtin_command[i]; i++)
{
if (_strcmp(input_cmd, builtin_command[i]) == 0)
return (1);
}
return (0);
}
void handle_built_in(char **input_cmd, char **argv, int *stat, int cpt)
{
(void) argv;
(void) cpt;
if (_strcmp(input_cmd[0], "exit") == 0)
exit_cmd(input_cmd, stat)
else if (_strcmp(input_cmd[0], "env") == 0)
printenv(input_cmd, stat);
}
void exit_cmd (char **input_cmd, int *stat)
{
freeleak(input_cmd);
exit(*stat);
}
void printenv (char **input_cmd, int *stat)
{ 
int i;
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDERR_FILENO, "\n", 1);
}
freeleak(input_cmd);
(*stat) = 0;
}

