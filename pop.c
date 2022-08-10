#include "monty.h"

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *new;

	if (!*stack)
	{
		printf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	new = stack->next;
	free(stack);
	stack = new;
}
