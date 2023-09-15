#include "shell.h"
/**
 * main - simple shell
 *@ac: argument count
 *@av: array of arguments (strings)
 *return: 0 always success
 */
int main(void argc, char **argv[])
{
    char *line = NULL;
    char **cmd = NULL;
    int status;
    (void) ac;

    while (1)
    {
        line = read_cmd();
        cmd = spliter(line);
        status = _execve(cmd, argv);
        
    }
}
 