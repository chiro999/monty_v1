#include "monty.h"

/**
 * rotate_bottom - Rotates the stack to the bottom.
 * @head: Stack head.
 * @counter: Line number (unused in this function).
 * Return: No return value.
 */
void rotate_bottom(stack_t **head, __attribute__((unused)) unsigned int line_counter)
{
	stack_t *replica;

	replica = *head; /* Create a replica of the head. */

	if (*head == NULL || (*head)->next == NULL)
	{
		/* If the stack is empty or has only one element, there's nothing to rotate. */
		return;
	}

	while (replica->next)
	{
		/* Traverse the stack to find the last node (the current tail). */
		replica = replica->next;
	}

	replica->next = *head;       /* Make the last node (tail) point to the current head. */
	replica->prev->next = NULL;  /* Set the 'next' of the node before the tail to NULL. */
	replica->prev = NULL;        /* Set the 'prev' of the current tail to NULL. */
	(*head)->prev = replica;     /* Set the 'prev' of the current head to the new tail. */
	(*head) = replica;           /* Update the head to point to the new head (the previous tail). */
}
