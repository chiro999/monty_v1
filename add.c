#include "monty.h"
/**
 * add_stack2 - adds the top two elements of the stack.
 * @head: head of stack
 * @counter: line_number
 * Return: no return
 */
void add_stack2(stack_t **head, unsigned int line_counter)
{
	int len = 0;
	int tmp;

	/* Check if there are at least two elements in the stack */
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_counter);
		fclose(program.file);
		free(program.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Create a new node to hold the result of the addition */
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(program.file);
		free(program.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Calculate the sum of the top two elements and store it in 'tmp' */
	tmp = (*head)->n + (*head)->next->n;
	new_node->n = tmp;

	/* Update the new node's 'next' pointer to point to the element below the top two elements */
	new_node->next = (*head)->next->next;

	/* Update the stack's head to point to the new node */
	*head = new_node;

	/* Free the old top two nodes */
	free((*head)->next->next);
	free((*head)->next);
}
