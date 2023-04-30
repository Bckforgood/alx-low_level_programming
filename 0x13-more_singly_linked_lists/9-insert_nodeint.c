#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the head node of the linked list.
 * @idx: The index of the list where the new node should be added.
 * @n: The value to store in the new node.
 *
 * Return: If successful - a pointer to the new node.
 *         Otherwise - NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int i;

	if (!head)
		return (NULL);

	if (idx == 0)
		return (add_nodeint(head, n));

	current = *head;

	for (i = 0; i < idx - 1 && current; i++)
		current = current->next;

	if (i < idx - 1)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}

