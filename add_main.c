#include "shell.h"
/**
 * main - create nodes for path
 * Return: Always is 0
 */
int main(void)
{
	const char *name = "PATH";
	char *nodevalue;
	path_t *head;

	head = NULL;
	nodevalue = _getenv(name);
	nodevalue = strtok(nodevalue, ":");
	while(nodevalue != NULL)
	{
		add_path(&head, nodevalue);
		nodevalue = strtok(NULL, ":");
	}
	print_list(head);
	free_list(head);
	return (0);
}
