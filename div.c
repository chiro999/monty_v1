#include "monty.h"
/**
 * div_stack2 - divides the top two elements of the stack.
 * @head: stack head
 * @line_counter: line number
 * Return: no return
 */
void div_stack2(stack_t **head, unsigned int line_counter)
{
    int len = 0;
    int tmp;

    /* Check if there are at least two elements in the stack */
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_counter);
        fclose(program.file);
        free(program.line_content);
        stack_free(*head);
        exit(EXIT_FAILURE);
    }

    /* Create a new node to hold the result of the division */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(program.file);
        free(program.line_content);
        stack_free(*head);
        exit(EXIT_FAILURE);
    }

    /* Check for division by zero */
    if ((*head)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_counter);
        fclose(program.file);
        free(program.line_content);
        stack_free(*head);
        exit(EXIT_FAILURE);
    }

    /* Calculate the result of the division and store it in 'tmp' */
    tmp = (*head)->next->n / (*head)->n;

    /* Update the new node's value */
    new_node->n = tmp;

    /* Update the new node's 'next' pointer to point to the element below the top two elements */
    new_node->next = (*head)->next->next;

    /* Update the stack's head to point to the new node */
    *head = new_node;

    /* Free the old top two nodes */
    free((*head)->next->next);
    free((*head)->next);
}
