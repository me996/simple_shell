#include "shell.h"

char **tokenizer(char *cmd)
{
    char *token = NULL, *dup = NULL;
    char **command = NULL;
    int count = 0, i = 0;
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
        count++;
        token = strtok(NULL, DELIM);
    }
    free(dup), dup = NULL;
    command = malloc (sizeof(char *) * (count + 1));
    if (!command)
    {
        free(cmd), cmd = NULL;
        return (NULL);
    }
    token = strtok(cmd, DELIM);
    while (token)
    {
        command[i] = _strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    free(cmd), cmd = NULL;
    command [i] = NULL; 
    return(command);
}


