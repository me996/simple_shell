#include "shell.h"
/**
 * main - main function
 * @argc: arguments count
 * @argv: Arguments vector
 * Return: 0 Always success, 1 on error
*/

int main (int argc, char **argv)
{
char *cmd = NULL, **command = NULL;
int status = 0;
(void) argc;


while(1)
{
cmd = readcmd();
if (cmd == NULL) /*ctr+D*/
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
return (status);
}
	
command = tokenizer(cmd);
if (!command)
continue;
status = _execute(command, argv);
}
}
