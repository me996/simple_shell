#include "shell.h"

/**
 * _getpath - searches for and returns
 *
 * @line: A null-terminated string representing the command to search for
 *
 * Return: A pointer to a string storing
 */

char *_getpath(char *line)
{
char *pathenv, *command, *directory;
int i;
struct stat file_info;
for (i = 0; line[i]; i++)
{
if (line[i] == '/')
{
if (stat(line, &file_info) == 0)
return (_strdup(line));
return (NULL);
}
}
pathenv = _getenv("PATH");
if (!pathenv)
return (NULL);
directory = strtok(pathenv, ":");
while (directory)
{
command = malloc(_strlen(directory) + _strlen(line) + 2);
if (command)
{
_strcpy(command, directory);
_strcat(command, "/");
_strcat(command, line);
if (stat(command, &file_info) == 0)
{
free(pathenv);
return (command);
}
free(command), command = NULL;
directory = strtok(NULL, ":");
}
}
free(pathenv);
return (NULL);
}


