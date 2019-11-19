#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

size_t _getline(char **buffer, size_t *n, FILE *stream);
char *_strtok(char *str, char *tokens);
#endif
