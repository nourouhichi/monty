#include "monty.h"
/**
 * nothing - useless
 * @stack: same
 * @n:same
 */
void nothing(stack_t **stack, unsigned int n)
{
	(void)stack;
	(void)n;
}
/**
 * sub - substractes tow top elements of the linekd list
 * @stack: the linked list
 * @n: number of lines in case of error
 */
void sub(stack_t **stack, unsigned int n)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	remove_top(stack, n);
}
/**
 * divi - divides the tow top elements of a list
 * @stack: same
 * @n: same
 */
void divi(stack_t **stack, unsigned int n)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
			fprintf(stderr, "L%d: division by zero\n", n);
			exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	remove_top(stack, n);

}
/**
 * mult - multiplies
 * @stack:same
 * @n:same
 */
void mult(stack_t **stack, unsigned int n)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	remove_top(stack, n);
}
