#include "monty.h"

/**
 * _exec - Executes the opcode.
 * @stack: Head linked list - stack.
 * @line_counter: Line number.
 * @file: Pointer to the Monty file.
 * @line_content: Line content.
 * Return: 0 on success, 1 if the opcode is unknown.
 */
int _exec(char *line_content, stack_t **stack, unsigned int line_counter, FILE *file)
{
        instruction_t opst[] = {
        {"push", _push},
        {"pall", _print_all},
        {"pint", print_int},
        {"pop", _pop},
        {"swap", _swap},
        {"add", add_stack2},
        {"nop", _nop},
        {"sub", sub_stack2},
        {"div", div_stack2},
        {"mul", mul_stack2},
        {"mod", mod_stack2},
        {"pchar", print_char},
        {"pstr", print_str},
        {"rotl", rotate_top},
        {"rotr", rotate_bottom},
        {"queue", _queue},
        {"stack", _stack},
        {NULL, NULL}
    };

	unsigned int i = 0;
	char *op;

	op = strtok(line_content, " \n\t"); /* Tokenize the line_content to get the opcode. */

	if (op && op[0] == '#')
		return (0); /* If the line starts with '#' (a comment), do nothing. */

	program.var = strtok(NULL, " \n\t"); /* Tokenize to get the argument (if any). */

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_counter); /* Execute the corresponding function for the opcode. */
			return (0); /* Return success (opcode found and executed). */
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, op); /* Unknown opcode error message. */
		fclose(file);
		free(line_content);
		stack_free(*stack);
		exit(EXIT_FAILURE); /* Exit the program with an error status. */
	}

	return (1); /* Return 1 to indicate an unknown opcode. */
}
