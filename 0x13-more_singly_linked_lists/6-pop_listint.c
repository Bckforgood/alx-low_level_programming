#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to a pointer to the first node of the list
 *
 * Return: the head node's data (n), or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
        int data;
        listint_t *temp;

        if (*head == NULL) /* empty list */
                return (0);

        data = (*head)->n; /* store head node's data */
        temp = *head; /* save head node pointer */

        *head = (*head)->next; /* update head node */

        free(temp); /* free original head node */

        return (data);
}
