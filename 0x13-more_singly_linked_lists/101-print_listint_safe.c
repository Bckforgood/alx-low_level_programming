#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: Pointer to the head node of the list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *curr = head;
	const listint_t *printed[100];
	size_t printed_count = 0;
	int loop_detected = 0;

	while (curr)
	{
		size_t i;

		/* Check if this node has already been printed */
		for (i = 0; i < printed_count; i++)
		{
			if (curr == printed[i])
			{
				printf("-> [%p] %d\n", (void *)curr, curr->n);
				loop_detected = 1;
				break;
			}
		}

		if (loop_detected)
		{
			break;
		}

		printf("[%p] %d\n", (void *)curr, curr->n);
		printed[printed_count++] = curr;
		count++;

		curr = curr->next;
	}

	return (count);
}
