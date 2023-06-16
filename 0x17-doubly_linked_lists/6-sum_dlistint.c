#include "lists.h"
/**
 * sum_dlistint - returns the sum of all the data of the list.
 * @head: list pointer
 * Return:  sum of all data in the list but 0 if is empty.
 **/
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *nx = head;
	int i = 0;

	while (nx)
	{
		i += nx->n;
		nx = nx->next;
	}

	return (i);
}
