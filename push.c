#include "monty.h"
/**
 * push - adds an element to a stack
 * @stack: stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeList(stack);
	}

	(void)line_number;

	if (*stack)
		(*stack)->prev = node;

	node->prev = NULL;
	node->next = *stack;
	node->n = 0;
	*stack = node;
}