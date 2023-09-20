#include "monty.h"

/**
 * _pop - removes the top element from the head of the stack
 * @head: head of the stack
 * @line_counter: line_number
 * Return: no return
 */
void _pop(stack_t **head, unsigned int line_counter)
{
    stack_t *new_node;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
        fclose(program.file);
        free(program.line_content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    new_node = *head;
    *head = new_node->next;
    free(new_node);
}
