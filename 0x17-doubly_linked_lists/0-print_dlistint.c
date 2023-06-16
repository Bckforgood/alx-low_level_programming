#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer list.
 * Return: nodes numbers .
 **/
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *nx = h;
	size_t a = 0;

	while (nx)
	{
		printf("%i\n", nx->n);
		a++;
		nx = nx->next;
	}

	return (a);
}
