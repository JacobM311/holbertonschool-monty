#include "monty.h"

/**
 * push - adds an element to a stack
 * @stack: linked list stack to push to
 * @line_number: current line number of bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeList(stack);
	}

	(void)line_number;

	if (*stack)
		(*stack)->prev = newNode;

	return (new);
}