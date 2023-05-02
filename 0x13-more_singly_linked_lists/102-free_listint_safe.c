#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: Pointer to the head node of the list
 *
 * Return: Number of nodes in the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *current, *next;

    if (!h || !*h)
        return (0);

    current = *h;
    while (current)
    {
        /* Keep a pointer to the next node before freeing the current node */
        next = current->next;
        
        /* Free the current node and increment the counter */
        free(current);
        count++;
        
        /* Check if the address of the next node is lower than or equal to the */
        /* address of the current node. If true, it means that we have a cycle */ 
        /* in the list, so we break the loop to avoid an infinite loop */
        if (next <= current)
        {
            printf("-> [%p] %d\n", (void *)next, next->n);
            break;
        }
        
        /* Move to the next node */
        current = next;
    }
    
    /* Set the head pointer to NULL*/
    *h = NULL;

    return (count);
}

