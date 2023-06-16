#include "lists.h"
/**
 * free_dlistint - frees a dlistint_t list
 * @head: list pointer
 * Return: void
 **/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node;
	dlistint_t *next_node;

	if (head)
	{
		current_node = head;
		next_node = head->next;
		while (next_node)
		{
			free(current_node);
			current_node = next_node;
			next_node = next_node->next;
		}
		free(current_node);
	}
}
