#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct program_s
{
	char *var;
	FILE *file;
	char *line_content;
	int change_ds;
} program_t;
extern program_t program;


/* program functions */
void add_stack2(stack_t **head, unsigned int line_counter);
void add_node(stack_t **head, int n);
void div_stack2(stack_t **head, unsigned int line_counter);
void mod_stack2(stack_t **head, unsigned int line_counter);
void mul_stack2(stack_t **head, unsigned int line_counter);
void _nop(stack_t **head, unsigned int line_counter);
void _pop(stack_t **head, unsigned int line_counter);
void _print_all(stack_t **head, unsigned int line_counter);
void print_char(stack_t **head, unsigned int line_counter);
void print_int(stack_t **head, unsigned int line_counter);
void print_str(stack_t **head, unsigned int line_counter);
void _push(stack_t **head, unsigned int line_counter);
void _queue(stack_t **head, unsigned int counter);
void _stack(stack_t **head, unsigned int line_counter);
void stack_free(stack_t *head);
void sub_stack2(stack_t **head, unsigned int line_counter);
void _swap(stack_t **head, unsigned int line_counter);
void rotate_bottom(stack_t **head, __attribute__((unused)) unsigned int line_counter);
void rotate_top(stack_t **head, __attribute__((unused)) unsigned int line_counter);

#endif

