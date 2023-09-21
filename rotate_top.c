#include "monty.h"

/**
 * rotate_top - Rotates the stack to the top.
 * @head: Stack head.
 * @line_counter: Line number (unused in this function).
 * Return: No return value.
 */
void rotate_top(stack_t **head, __attribute__((unused)) unsigned int line_counter)
{
	stack_t *tmp = *head, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		/* If the stack is empty or has only one element, there's nothing to rotate. */
		return;
	}

	temp2 = (*head)->next; /* Store the second element of the stack in 'temp2'. */
	temp2->prev = NULL;    /* Set the 'prev' of 'temp2' to NULL. */

	while (tmp->next != NULL)
	{
		/* Traverse the stack to find the last node. */
		tmp = tmp->next;
	}

	tmp->next = *head;   /* Make the last node point to the current head. */
	(*head)->next = NULL; /* Set the 'next' of the current head to NULL. */
	(*head)->prev = tmp;  /* Set the 'prev' of the current head to the last node. */
	(*head) = temp2;      /* Update the head to point to the new head 'temp2'. */
}
