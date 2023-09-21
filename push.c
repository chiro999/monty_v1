#include "monty.h"

/*
 * _push - add node to the stack
 * @head: stack head
 * @line_counter: line number
 * Return: no return
 */
void _push(stack_t **head, unsigned int line_counter)
{
    int n;
    int j = 0;
    int not_int = 0;

    /* Check if program.var is not NULL */
    if (program.var != NULL)
    {
        /* Check if the first character is a minus sign for negative integers */
        if (program.var[0] == '-')
            j++;

        /* Iterate through each character of program.var */
        for (; program.var[j] != '\0'; j++)
        {
            /* Check if the character is not a digit (0-9) */
            if (program.var[j] < '0' || program.var[j] > '9')
                not_int = 1;
        }

        /* If not_int is 1, the input is not a valid integer */
        if (not_int == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_counter);
            fclose(program.file);
            free(program.line_content);
            stack_free(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Handle the case where program.var is NULL */
        fprintf(stderr, "L%d: usage: push integer\n", line_counter);
        fclose(program.file);
        free(program.line_content);
        stack_free(*head);
        exit(EXIT_FAILURE);
    }

    /* Convert the validated program.var to an integer */
    n = atoi(program.var);

    /* Check the value of program.change_ds to determine whether to add to the stack or queue */
    if (program.change_ds == 0)
        add_node(head, n);
    else
        add_queue(head, n);
}
