#include "shell.h"
char *read_cmd (void)
{
    char *cmd = NULL;
    size_t len = 0;
    ssize_t n;
    write(STDOUT_FILENO, "$ ", 2);
    n = getline(&cmd, &len, stdin);
    if (n == -1)
    {
        free(cmd);
        return(NULL);
    }
return(cmd);
}