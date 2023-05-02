#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 *                           in a listint_t linked list.
 * @head: A pointer to a pointer to the head node of the linked list.
 * @idx: The index of the list where the new node should be added.
 *       Index starts at 0.
 * @n: The integer data of the new node.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - Address of the new node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *prev_node, *current_node = *head;
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (current_node != NULL && i < idx)
	{
		prev_node = current_node;
		current_node = current_node->next;
		i++;
	}

	if (i != idx)
	{
		free(new_node);
		return (NULL);
	}

	prev_node->next = new_node;
	new_node->next = current_node;

	return (new_node);
}
