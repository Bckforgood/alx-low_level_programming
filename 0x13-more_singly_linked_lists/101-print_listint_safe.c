#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Pointer to the beginning of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *curr = head, *prev = NULL;
	size_t count = 0;
	int first_repeat_found = 0;

	while (curr)
	{
		printf("[%p] %d\n", (void *)curr, curr->n);
		count++;

		if (curr < prev && !first_repeat_found)
		{
			printf("-> [%p] %d\n", (void *)curr, curr->n);
			first_repeat_found = 1;
		}

		prev = curr;
		curr = curr->next;
	}

	if (!first_repeat_found)
		printf("-> [NULL]\n");

	return (count);
}

