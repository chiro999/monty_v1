#include "monty.h"

/**
 * mul_stack2 - multiplies the top two elements of the stack.
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
 */
void mul_stack2(stack_t **head, unsigned int line_counter)
{
    stack_t *new_node;
    int len = 0, tmp;

    /* Count the number of elements in the stack */
    new_node = *head;
    while (new_node)
    {
        new_node = new_node->next;
        len++;
    }

    /* Check if there are at least 2 elements on the stack */
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_counter);
        fclose(program.file);
        free(program.line_content); // Changed from bus.content to program.line_content
        stack_free(*head);
        exit(EXIT_FAILURE);
    }

    new_node = *head;

    /* Calculate the product of the top two elements */
    tmp = new_node->next->n * new_node->n;

    /* Update the second element from the top with the result */
    new_node->next->n = tmp;

    /* Update the head to point to the new top element */
    *head = new_node->next;

    /* Free the old top element */
    free(new_node);
}
