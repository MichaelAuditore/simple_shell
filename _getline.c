#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
size_t _getline(char **buffer, size_t *n, FILE *stream)
{
	int length;
	do{
		write(1, "$ ", 2);
		if ((read(STDIN_FILENO, *buffer, *n)) > 0)
			write(1, "$ ", 2);
		if (!((read(STDIN_FILENO, *buffer, *n)) > 0))
		{
			free(*buffer);
			write(1, "\n", 1);
			break;
		}
		else
			write(1, "$ ", 2);
	}
	while ((length = read(STDIN_FILENO, *buffer, *n)) > 0);
	return (length);
}
