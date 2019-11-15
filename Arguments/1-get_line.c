#define _GNU_SOURCE
#include "shell.h"

int main(void)
{
	char *buffer = NULL;
	int lenbuf = 0;

	while (1)
	{
		lenbuf = _getline(&buffer);
		if (lenbuf == 0)
			continue;
		else if (lenbuf == -1)
		{
			free(buffer);
			write(STDOUT_FILENO, "Can't read the command or find EOF\n", 25);
			exit(-1);
		}
		else if (lenbuf > 0)
		{
			write(STDOUT_FILENO, buffer, lenbuf);
			printf("len if buf %d\n", lenbuf);
			free(buffer);
		}
		else if (lenbuf == EOF)
			exit(98);
	}
	return (0);
}
