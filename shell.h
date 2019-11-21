#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stddef.h>
/**
 * struct path - singly linked list
 * @path: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct path
{
	char *path;
	struct path *next;
} path_t;
char *_getenv(const char *name);
int _strlen(char *str);
void printpath(void);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
size_t _getline(char **buffer, size_t *n, FILE *stream);
char *_strtok(char *str, char *tokens);
char *_strdup(char *str);
size_t print_list(const path_t *h);
int _setenv(char *name, char *value, int overwrite);
path_t *add_path(path_t **head, const char *str);
void free_list(path_t *head);
#endif
