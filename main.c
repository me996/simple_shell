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
    char **command = NULL, *line = NULL;
    int i, status = 0;
    (void) argc;
    (void) argv;
    
    while (1)
    {
        cmd = read_cmd();
        if (cmd == NULL) /*end of file*/
        {
            write(STDOUT_FILENO, "\n", 1);
           return (status);
        }
        command = splitter(line);
        if (!command)
        continue;

        for (i = 0; command[i]; i++)
        printf("%s\n", command[i]);
        







        /*status = _execve(cmd, argv);*/

    }
}
