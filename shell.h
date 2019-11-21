#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
char *_getenv(const char *name);
void printpath(void);
int _strcmp(char *s1, char *s2);
size_t _getline(char **buffer, size_t *n, FILE *stream);
char *_strtok(char *str, char *tokens);
#endif
