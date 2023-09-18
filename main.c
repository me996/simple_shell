#include "shell.h"
/**
 * main - simple shell
 *@argc: argument count
 *@argv: array of arguments (strings)
 *Return: 0 always success
 */
int main(int argc, char **argv)
{
    char *line = NULL, **command = NULL;
    int i, status = 0;
    (void) argc;
    (void) argv;
   
    while (1)
    {
        line = readline();
        if (line == NULL) /*end of file*/
        {
            write(STDOUT_FILENO, "\n", 1);
           return (status);
        }
        command = tokenizer(line);
        if (!command)
        continue;

       for (i = 0; command[i]; i++)
       {
        printf("%s\n", command[i]);
        free(command[i]), command[i] = NULL;
       }
        free(command), command = NULL;






        /*status = _execve(cmd, argv);*/

    }
}
