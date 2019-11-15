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
		dprintf(1, "$ ");
	}
	while ((length = read(STDIN_FILENO, *buffer, *n)) == 0);
	return (length);
}
int main()
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	/* dprintf(1, "$ "); */
	characters = _getline(&buffer,&bufsize, stdin);
	printf("%s",buffer);
	printf("the len of input %li\n", characters);
	return(0);
}
