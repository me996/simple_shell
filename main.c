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
    int status = 0;
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
        status = _execute(command, argv);

    }
}
