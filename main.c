#include "monty.h"
program_t program = {NULL, NULL, NULL, 0};

/* Main function for the Monty code interpreter */
int main(int argc, char *argv[])
{
    char *line_content; /* Variable to store the content of each line */
    FILE *file; /* File pointer for the Monty file */
    size_t size = 0;
    ssize_t read_line = 1; /* Stores the result of getline, initialized to 1 */
    stack_t *stack = NULL; /* Stack for executing Monty commands */
    unsigned int line_counter = 0; /* Counter for tracking the line number in the Monty file */

    /* Check if the correct number of command-line arguments is provided */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the Monty file for reading */
    file = fopen(argv[1], "r");
    program.file = file;

    /* Check if the file could be opened successfully */
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Read lines from the Monty file and execute commands */
    while (read_line > 0)
    {
        line_content = NULL;
        read_line = getline(&line_content, &size, file); /* Read a line from the file */
        program.line_content = line_content; /* Store the current line content */
        line_counter++; /* Increment the line counter */

        if (read_line > 0)
        {
            _exec(line_content, &stack, line_counter, file); /* Execute the Monty command on the current line */
        }

        free(line_content); /* Free memory allocated by getline */
    }

    stack_free(stack); /* Clean up the stack */
    fclose(file); /* Close the Monty file */

    return (0);
}
