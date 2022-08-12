#include "monty.h"

void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *seek, *swap;
	int n;

	if (!*stack || (((!(*stack)->prev)) && (!(*stack)->next)))
	{/*there are less than 2 nodes*/
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		opCommand[3] = "ERROR";
		return;
	}
	for (seek = *stack; seek->prev; seek = seek->prev)
	;/*find the top*/
	swap = seek->next;
	n = seek->n;
	seek->n = swap->n;
	swap->n = n;
}
