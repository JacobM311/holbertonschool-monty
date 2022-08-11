#include "monty.h"

/**
 * pop - frees the head node.
 * @stack: the stack.
 * @line_number: line number.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	free(stack);
	*stack = new;
}
