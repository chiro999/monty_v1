#include "monty.h"
/**
 * stack_free - frees a doubly linked list
 * @head: head of the stack
 */
void stack_free(stack_t *head)
{
    stack_t *tmp;

    tmp = head;
    while (head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}
