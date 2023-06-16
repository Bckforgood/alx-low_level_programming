#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list.
 * @h: list pointer
 * Return: node numbers
 **/
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *nx = h;
	size_t a = 0;

	while (nx)
	{
		a++;
		nx = nx->next;
	}
	return (a);
}
