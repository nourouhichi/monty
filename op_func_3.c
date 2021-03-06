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
/**
 * pstr - printd a string
 * @stack: same
 * @n: same
 */
void pstr(stack_t **stack , unsigned int n)
{
	stack_t *roadrunner = *stack;

	(void)n;
	if (!*stack)
	{
		putchar('\n');
		return;
	}
	while (roadrunner)
	{
		if((roadrunner)->n <= 0 || (roadrunner)->n > 127 || roadrunner->n < 65)
			break;
		putchar(roadrunner->n);
		roadrunner = roadrunner->next;
	}
		putchar('\n');
}
/**
 * rotl - rotates
 * @stack: same
 * @n: same
 */
void rotl(stack_t **stack, unsigned int n)
{
	stack_t *roadrunner = *stack, *new_head = (*stack)->next, *bowl = *stack;

	(void)n;
	if (!*stack || !(*stack)->next)
		return;
	while (roadrunner->next)
		roadrunner = roadrunner->next;
	bowl->next = NULL;
	bowl->prev = roadrunner;
	roadrunner->next = bowl;
	new_head->prev = NULL;
	*stack = new_head;
}
