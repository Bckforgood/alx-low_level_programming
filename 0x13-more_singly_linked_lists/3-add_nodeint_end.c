#include "lists.h"
#include <stdlib.h>
/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: A pointer to a pointer to the head of the listint_t list.
 * @n: The integer to be added to the listint_t list.
 *
 * Return: If the function fails - NULL.
 *Otherwise - a pointer to the new node at the end of the listint_t list.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *last_node = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (last_node->next != NULL)
		last_node = last_node->next;

	last_node->next = new_node;

	return (new_node);
}

