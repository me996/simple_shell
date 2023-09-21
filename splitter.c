#include "shell.h"
/**
 * tokenizer - Tokenize a string into an array of strings.
 * @cmd: The input string to tokenize.
 *
 * Return: An array of strings containing the tokens.
 *         NULL if cmd is NULL or memory allocation fails.
 */
char **tokenizer(char *cmd)
{
char *token = NULL, *dup = NULL;
char **command = NULL;
int i = 0, cout = 0;
if (!cmd)
return (NULL);
dup = _strdup(cmd);
token = strtok(dup, DELIM);
if (token == NULL)
{
free(cmd), cmd = NULL;
free(dup), dup = NULL;
return(NULL);
}
while (token)
{
cout++;
token = strtok(NULL, DELIM);
}
free(dup), dup = NULL;
command = malloc(sizeof(char *) * (cout + 1));
if (!command)
{
free(cmd), cmd = NULL;
return (NULL);
}
token = strtok(cmd, DELIM);
while (token)
{
command[i++] = _strdup(token);
token = strtok(NULL, DELIM);
}
free(cmd), cmd = NULL;
command[i] = NULL;
return(command);
}
