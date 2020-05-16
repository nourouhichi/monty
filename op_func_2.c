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
	stack_t *bowl = (*stack)->next->next;

        if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	(*stack)->n -= (*stack)->next->n;
	free((*stack)->next);
	if (bowl)
		(*stack)->next = bowl;
	else
		(*stack)->next = NULL;
}

