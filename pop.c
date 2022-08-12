#include "monty.h"

/**
 * pop - frees the head node.
 * @stack: the stack.
 * @line_number: line number.
 */

void pop(stack_t **stack, unsigned int line_number)
{
		stack_t *hide;

	if (!*stack)/*there is no stack*/
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		op[3] = "ERROR";
		return;
	}
	hide = *stack;
	while (hide->prev)/*find the top*/
		hide = hide->prev;
	if (hide->next) /*makes next node top*/
		hide->next->prev = NULL;
	if (hide == *stack)
	{/*makes sure we retain access to list*/
		if ((*stack)->next)/*there is a second node*/
			*stack = (*stack)->next;
		else/*there are no more nodes*/
			*stack = NULL;
	}
	free(hide);/*free the top node*/
}
