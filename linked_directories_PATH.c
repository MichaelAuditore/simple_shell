#include "shell.h"
/**
 * add_path - add node of each path at the end
 * @head: Address of linked list
 * @str: String to copy and create node
 * Return: Address of linked list with the new node
 */
path_t *add_path(path_t **head, const char *str)
{
	path_t *tmp;
	path_t *last = *head;

	tmp = malloc(sizeof(path_t));
	if (tmp == NULL)
		return (NULL);

	if (str != NULL)
		tmp->path = (void *)str;
	else
		tmp->path = "(nil)";
	tmp->next = NULL;
	if (*head == NULL)
	{
		*head = tmp;
		return (tmp);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	return (tmp);
}
/**
 * free_list - free the memory of each node in the list
 * @head: Address of the list
 */
void free_list(path_t *head)
{
	path_t *current = head;
	path_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
