#include "shell.h"
char **splitter(char *line)
{
    char *token = NULL, *dup = NULL;
    char **command = NULL;
    int cout = 0, i = 0;
    if (!line)
    return (NULL);
    dup = _strdup(line);
    token == strtok(dup, DELIM);
    if (token == NULL)
    {
        free(line), line = NULL;
        free(dup), dup = NULL;
        return(NULL);
    }
    while (token)
    {
        cout++;
        token = strtok(NULL, DELIM);
    }
    free(dup), dup = NULL;
    command = malloc (sizeof(char *) * (cout + 1));
    if (!command)
    {
        free(line), line = NULL;
        return (NULL);
    }
    token == strtok(line, DELIM);
    while (token)
    {
        command[i] = _strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    free(line), line = NULL;
    command [i] = NULL; 
    return(command);
}

