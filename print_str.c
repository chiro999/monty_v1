#include "monty.h"

/**
 * print_str - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
 */
void print_str(stack_t **head, unsigned int line_counter)
{
	stack_t *new_node;
	(void)line_counter;

	new_node = *head;
	while (new_node)
	{
		if (new_node->n > 127 || new_node->n <= 0)
		{
			break;
		}
		printf("%c", new_node->n);
		new_node = new_node->next;
	}
	printf("\n");
}
