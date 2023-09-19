#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - The main function of the C program.
 * @argc: no. of inputs
 *@argv: string array inputs
 * Return: Returns 0 upon successful
 */

int main(int argc, char **argv)
{
processInput(argc, argv);
return (0);
}
