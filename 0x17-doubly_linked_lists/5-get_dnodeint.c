#include "lists.h"
/**
 * get_dnodeint_at_index -  returns the nth node of a dlistint_t linked list.
 * @head: list pointer of the first node
 * @index: @index: The index of the node to retrieve.
 * Return: on success pointer to first node, null if failed
 **/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *nx = head;
	unsigned int a = 0;

	while (nx && t != index)
	{
		a++;
		nx = nx->next;
	}
	if (nx && a == index)
		return (nx);
	return (NULL);
}
