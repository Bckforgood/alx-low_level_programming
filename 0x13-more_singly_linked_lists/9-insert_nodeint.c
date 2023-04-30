#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the head node of the linked list.
 * @idx: The index of the list where the new node should be added.
 * @n: The integer to store in the new node.
 *
 * Return: A pointer to the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *current = *head, *new_node;

	if (idx == 0)
		return (add_nodeint(head, n));

	while (current && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (!current)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}

