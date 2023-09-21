#include "monty.h"
/**
 * add_stack2 - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void add_stack2(stack_t **head, unsigned int counter)
{
	stack_t *new_node;
	int len = 0, tmp;

	new_node = *head;
	while (new_node)
	{
		new_node = new_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_node = *head;
	tmp = new_node->n + new_node->next->n;
	new_node->next->n = tmp;
	*head = new_node->next;
	free(new_node);
}
