#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define DELIM " \t\n"
int main(int argc, char **argv);
char *_getpath(char *line);
char *readcmd(void);
int _strlen(char *s);
char **tokenizer(char *cmd);
int _execute(char **command, char **argv, int cpt);
void freeleak(char **array);
void printerror(char *name, char *cmd, int cpt);
char *_itoa(int s);
void reverse_string(char *s, int len);
int built_in(char *input_cmd);
void handle_built_in(char **input_cmd, char **argv, int *stat, int cpt);
void printenv(char **input_cmd, int *stat);
void exit_cmd(char **input_cmd, char **argv, int *stat, int cpt);
int _atoi(char *s);
int positive_num(char *s);

int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
extern char **environ;

char *_getenv(char *var);


#endif

