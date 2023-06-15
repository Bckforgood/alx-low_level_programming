#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_dlistint - Prints the content of a doubly linked list
 * @h: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *curr = h;
	size_t nc = 0;

	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
		nc++;
	}

	return (nc);
}
