#include "monty.h"

/**
 * _queue - Sets the behavior of the stack to queue mode (FIFO).
 * @head: Stack head (unused in this function).
 * @counter: Line number (unused in this function).
 * Return: No return value.
 */
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;    /* This is used to suppress the "unused parameter" warning. */
	(void)counter; /* This is used to suppress the "unused parameter" warning. */

	program.change_ds = 1; /* Sets a global variable 'program.change_ds' to 1, indicating queue mode. */
}

/**
 * add_queue - Adds a new node with a given value to the end of the stack (queue).
 * @n: New value to be added to the stack.
 * @head: Pointer to the head of the stack.
 * Return: No return value.
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	tmp = *head; /* Initialize 'tmp' with the current head of the stack. */

	new_node = malloc(sizeof(stack_t)); /* Allocate memory for a new node. */
	if (new_node == NULL)
	{
		printf("Error\n"); /* Print an error message if malloc fails (usually better to use fprintf(stderr, ...) for error messages). */
	}

	new_node->n = n;       /* Set the value of the new node to 'n'. */
	new_node->next = NULL; /* Initialize the 'next' pointer of the new node to NULL. */

	if (tmp)
	{
		/* If the stack is not empty (tmp is not NULL), traverse the stack to find the last node. */
		while (tmp->next)
			tmp = tmp->next;
	}

	if (!tmp)
	{
		/* If the stack is empty (tmp is NULL), set the new node as the head. */
		*head = new_node;
		new_node->prev = NULL; /* Set the 'prev' pointer of the new node to NULL. */
	}
	else
	{
		/* If the stack is not empty, append the new node to the end. */
		tmp->next = new_node; /* Set the 'next' pointer of the last node to the new node. */
		new_node->prev = tmp; /* Set the 'prev' pointer of the new node to the last node. */
	}
}
