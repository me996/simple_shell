#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#define DELIM " \t\n"

int main(int argc, char **argv);
char *readline (void);
char **tokenizer(char *line);
extern char **environ;
int _execute (char **command, char **argv);
void freecmd (char **array);


char *_strdup(const char *s);
















#endif
