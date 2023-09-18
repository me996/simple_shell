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
#define DELIM "\t\n"

int main(int argc, char **argv);
char **tokenizer(char *line);

char *readline (void);

char *_strdup(const char *s);
















#endif
