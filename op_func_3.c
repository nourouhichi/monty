#include "monty.h"
/**
 * pchar - prints a char
 * @stack: same
 * @n:same
 */
void pchar(stack_t **stack, unsigned int n)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n >= 65) && ((*stack)->n <= 127))
	{
		putchar((*stack)->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", n);
		exit(EXIT_FAILURE);
	}
}
