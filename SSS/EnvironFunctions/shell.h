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
char *_strdup(char *str);
char **_copyenvdp(char **str, int old_size, int new_size);
void freedp(char **str);
char ** _setenv(char **environ, const char *name, const char *value);

#endif
