#include "monty.h"
/**
 * sub_stack2 - subtraction
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
 */
void sub_stack2(stack_t **head, unsigned int line_counter)
{
    stack_t *new_node;
    int difference, len;

    new_node = *head;

    for (len = 0; new_node != NULL; len++)
        new_node = new_node->next;

    if (len < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_counter);
        fclose(program.file);
        free(program.line_content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    new_node = *head;
    difference = new_node->next->n - new_node->n;
    new_node->next->n = difference;
    *head = new_node->next;
    free(new_node);
}
