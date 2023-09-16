#include "shell.h"
/**
 * main - simple shell
 *@ac: argument count
 *@av: array of arguments (strings)
 *Return: 0 always success
 */
int main(int argc, char **argv)
{
    char *cmd = NULL;
    /*char **cmd = NULL;*/
    int status = 0;
    (void) argc;
    (void) argv;
    write(STDOUT_FILENO, "$ ", 2);
    while (1)
    {
        cmd = read_cmd();
        if (cmd == NULL) /*end of file*/
        {
            write(STDOUT_FILENO, "\n", 1);
           return (status);
        }
        free (cmd);
        /*cmd = spliter(line);*/
        /*status = _execve(cmd, argv);*/

    }
}
 
