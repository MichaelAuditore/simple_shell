#include "shell.h"
/**
 * printpath - start to find a variable
 */
void printpath(void)
{
	const char *name = "PATH";
	char *value;

	value = _getenv(name);
	value = strtok(value, ":");
	while (value != NULL)
	{
		printf("%s\n", value);
		value = strtok(NULL, ":");
	}
}
