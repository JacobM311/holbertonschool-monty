include "main.h"
/**
 * pint - prints the top of stack value
 * @stack: the stack
 * @line_number: line number
 */
void(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        printf(stderr, "L%u: can't pint, stack empty")
        exit(EXIT_FAILTURE);
    }
    printf("%d\n", (*stack)->n);
}