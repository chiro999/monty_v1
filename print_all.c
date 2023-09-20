#include "monty.h"

/**
 * _print_all - prints the stack
 * @head: stack head
 * @line_counter: not used
 * Return: no return
 */
void _print_all(stack_t **head, unsigned int line_counter)
{
    stack_t *new_node;
    (void)line_counter;

    new_node = *head;
    if (new_node == NULL)
        return;
    while (new_node)
    {
        printf("%d\n", new_node->n);
        new_node = new_node->next;
    }
}
