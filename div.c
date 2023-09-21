void div_stack2(stack_t **head, unsigned int line_counter) {
    /* Check for division by zero */
    if ((*head)->n == 0) {
        fprintf(stderr, "L%d: division by zero\n", line_counter);
        fclose(program.file);
        free(program.line_content);
        stack_free(*head);
        exit(EXIT_FAILURE);
    }

    /* Calculate the result of the division and store it in 'tmp' */
    int tmp = (*head)->next->n / (*head)->n;

    /* Create a new node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(program.file);
        free(program.line_content);
        stack_free(*head);
        exit(EXIT_FAILURE);
    }

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
