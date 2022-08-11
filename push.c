#include "monty.h"
/**
 * push - adds node to head of list
 * @stack: stack
 * @line_number: line number of file where opcode is
 * 
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg
    stack_t node;

    node = malloc(sizeof(stack_t));

    if (!node)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);

    }
}