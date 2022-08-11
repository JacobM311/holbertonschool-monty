#include "monty.h"

void swap(stack_t **stack, unsigned int line_num)
{
    stack_t *temp = NULL;
	int i = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

    temp = *stack;
    i = temp->n;
    temp->n = i;
    temp->n = temp->next->n;
    temp->next->n = i;
}
