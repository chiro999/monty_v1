#include "monty.h"

/**
 * print_int - prints the integer at the top of the stack.
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
 */
void print_int(stack_t **head, unsigned int line_counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		fclose(program.file);
		free(program.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
