#include "lists.h"

/**
 * free_list - Frees a list_t list.
 * @head: A pointer to the list_t list to be freed.
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}
