#include "shell.h"

/**
 * built_in - checks if a command is a built-in command
 *
 * @input_cmd: The command to check
 *
 * Return: 1 if the command is built-in, 0 if not.
 */


int built_in(char *input_cmd)
{
char *builtin_command[] = { "exit", "env", "setenv", "unsetenv", "cd", NULL};
int i;
for (i = 0; builtin_command[i]; i++)
{
if (_strcmp(input_cmd, builtin_command[i]) == 0)
return (1);
}
return (0);
}

/**
 * handle_built_in - handles built-in commands
 *
 * @input_cmd: A null-terminated array of strings representing the user's input
 * @argv: A null-terminated array of strings
 * @stat: A pointer to an integer representing the program's exit status
 * @cpt: The current command counter
 *
 * Return: Nothing
 */

void handle_built_in(char **input_cmd, char **argv, int *stat, int cpt)
{
if (_strcmp(input_cmd[0], "exit") == 0)
exit_cmd(input_cmd, argv, stat, cpt);
else if
(_strcmp(input_cmd[0], "env") == 0)
printenv(input_cmd, stat);
}

/**
 * exit_cmd - exits the program
 *
 * @input_cmd: A null-terminated array of strings representing the user's input
 * @argv: A null-terminated array of strings
 * @stat: A pointer to an integer representing the program's exit status
 * @cpt: The current command counter
 *
 * Return: Nothing
 */

void exit_cmd(char **input_cmd, char **argv, int *stat, int cpt)
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

/**
 * printenv - prints the current environment variables to stdout
 *
 * @input_cmd: A null-terminated array of strings representing the user's input
 * @stat: A pointer to an integer representing the program's exit status
 *
 * Return: Nothing
 */
void printenv(char **input_cmd, int *stat)
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

