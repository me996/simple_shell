#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>

extern char **environ;
#define arr_len 500

size_t _strcspn(char *str, char *set);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strtok(char *str, char *delim, char **mvptr);

int _fgetc(FILE *stream);
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *dest, void *src, size_t n);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

char *_basename(char *path);
char *_strrchr(const char *str, int ch);
char *_strdup(char *src);
int _strlen(char *str);
int _atoi(const char *str);

int print_current_directory(void);

void processInput(int argc, char **argv);
void fillCommand(char **command);

void fillArgs2(char **argv, char **args);

void fillArgs(char *command, char **args);
void handleExit(char **args);
void handleEnv(void);
void executeCommand(char **args);
void handleCommandNotFound(char **args);

#endif
