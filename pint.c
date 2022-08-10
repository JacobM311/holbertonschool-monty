#include "monty.h"
/**
 * pint - prints the top of stack value
 * @stack: the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty", line_number)
        exit(EXIT_FAILTURE);
    }
    printf("%d\n", (*stack)->n);
}
