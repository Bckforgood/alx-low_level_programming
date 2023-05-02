#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: Pointer to the head node of the list
 *
 * Return: Number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    unsigned long printed = 0; /* bitset of printed node addresses */
    const listint_t *curr;

    if (!head)
        exit(98);

    curr = head;
    while (curr)
    {
        unsigned long addr = (unsigned long)curr;
        printf("[%p] %d\n", (void *)curr, curr->n);
        count++;
        curr = curr->next;
        if ((printed & (1UL << (addr % (sizeof(unsigned long) * 8)))) != 0)
        {
            printf("-> [%p] %d\n", (void *)curr, curr->n);
            count++;
            break;
        }
        printed |= 1UL << (addr % (sizeof(unsigned long) * 8));
    }
    return (count);
}

