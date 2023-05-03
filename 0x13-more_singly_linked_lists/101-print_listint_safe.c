#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list, handles loops
 *                     and prints a message if a loop is found.
 *
 * @head: A pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	long int diff;

	if (head == NULL)
		exit(98);

	while (head != NULL)
	{
		diff = head - head->next;
		count++;
		printf("[%p] %d\n", (void *)head, head->n);

		if (diff <= 0)
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}
		else
		{
			head = head->next;
		}
	}

	return (count);
}
