#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t list
 * @h: Double pointer to head of the linked list
 *
 * Return: The number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *current, *next;

    if (h == NULL || *h == NULL)
        return (count);

    current = *h;
    *h = NULL; /* Set the head to NULL */

    while (current != NULL)
    {
        next = current->next;
        free(current);
        count++;

        /* If next has already been visited, break the loop */
        if (next != NULL && next <= current)
        {
            printf("-> [%p] %d\n", (void *)next, next->n);
            break;
        }

        current = next;
    }

    return (count);
}

