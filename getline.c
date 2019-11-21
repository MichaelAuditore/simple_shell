#include "shell.h"
/**
 * _getline - wait for user to write something
 * @buffer: structure where it will be allocated the input received for user
 * @n: Size of structure
 * @stream: File to evaluate in this case input for user
 * Return: Length of what user wrote
 */
size_t _getline(char **buffer, size_t *n, FILE *stream)
{
	int length;

	do {
		write(1, "$ ", 2);
	} while ((length = read(STDIN_FILENO, *buffer, *n)) == 0);
	return (length);
}
