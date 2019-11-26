#include "shell.h"
/**
 * print_list - print all elements for a list
 * @h: Address of linked list
 * Return: Number of elements
 */
size_t print_list(const path_t *h)
{
	if (h != NULL && h->path != NULL)
	{
		printf("%s\n", h->path);
		return (print_list(h->next) + 1);
	}
	return (0);
}
