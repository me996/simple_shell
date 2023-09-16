#include "shell.h"
/**
 * main - simple shell
 *@argc: argument count
 *@argv: array of arguments (strings)
 *Return: 0 always success
 */
int main(int argc, char **argv)
{
    char *cmd = NULL;
    char **command = NULL;
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
        command = spliter(line);
        if (command == NULL)
        continue;
        /*status = _execve(cmd, argv);*/

    }
}
 
