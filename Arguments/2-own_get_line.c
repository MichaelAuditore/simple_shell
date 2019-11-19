#define _GNU_SOURCE
#include "shell.h"

ssize_t _getline(char **buffer)
{
	int len;

	*buffer = (char *)malloc(1024);
     while((len = read(STDIN_FILENO, *buffer, 1024)) == 0 && len != EOF);
	return (len);
}
