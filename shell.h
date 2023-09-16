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
char *read_cmd (void);
char *strtok(char *str, const char *delim);
char *_strdup(const char *s);
char *_strcat(char *dest, const char *src);
char **splitter(char *line);














#endif
