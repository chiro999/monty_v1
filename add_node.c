#include "monty.h"

/**
 * add_node - Adds a new node with a given value to the head of the stack.
 * @head: Pointer to the head of the stack.
 * @n: New value to be added to the stack.
 * Return: No return value.
 */
void add_node(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
