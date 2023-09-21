#include "monty.h"

/**
 * print_char - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
 */
void print_char(stack_t **head, unsigned int line_counter)
{
	stack_t *new_node;

	new_node = *head;
	if (!new_node)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_counter);
		fclose(program.file);
		free(program.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	if (new_node->n > 127 || new_node->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_counter);
		fclose(program.file);
		free(program.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", new_node->n);
}
