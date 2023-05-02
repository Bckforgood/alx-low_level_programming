#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: Pointer to the head node of the list
 *
 * Return: Number of nodes in the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next;

	if (!h || !*h)
	return (0);

	current = *h;
	while (current)
	{
		next = current->next;
		free(current);
		count++;
		if (next >= current)
		{
			printf("-> [%p] %d\n", (void *)next, next->n);
			break;
		}
		current = next;
	}
	*h = NULL;

	return (count);
}
