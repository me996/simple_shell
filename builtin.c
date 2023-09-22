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
if (_strcmp(input_cmd[0], "exit") == 0)
exit_cmd(input_cmd, argv, stat, cpt);
else if
(_strcmp(input_cmd[0], "env") == 0)
printenv(input_cmd, stat);
}
void exit_cmd (char **input_cmd,char **argv, int *stat, int cpt)
{
int value = (*stat);
char *idx, message[] = ": exit: Illegal number: ";
if (input_cmd[1])
{
if (positive_num(input_cmd[1]))
{
value = _atoi(input_cmd[1]);
}
else
{
idx = _itoa(cpt);
write(STDERR_FILENO, argv[0], _strlen(argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, idx, _strlen(idx));
write(STDERR_FILENO, message, _strlen(message));
write(STDERR_FILENO, input_cmd[1], _strlen(input_cmd[1]));
write(STDERR_FILENO, "\n", 1);
free(idx);
freeleak(input_cmd);
(*stat) = 2;
return;
}
}
freeleak(input_cmd);
exit(value);
}
void printenv (char **input_cmd, int *stat)
{ 
int i;
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
freeleak(input_cmd);
(*stat) = 0;
}
