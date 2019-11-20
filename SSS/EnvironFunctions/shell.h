#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

int _strlen(char *str);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _setenv(char *newenv);

#endif
