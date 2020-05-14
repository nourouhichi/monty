#include "header.h"
/**
 * print_from_stack - prints from the stack
 * @stack:pointer to the type
 * @n:number of lines
 */
void print_from_stack(stack_t **stack, unsigned int n)
{
	stack_t *roadrunner = *stack;

	(void) n;
	while (roadrunner)
	{
		printf("%d\n", roadrunner->n);
		roadrunner = roadrunner->next;
	}
}
/**
 * print_top - printd the top of the list
 * @stack: same
 * @n:same
 */
void print_top(stack_t **stack, unsigned int n)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * remove_top - deletes a node from the list
 * @stack:same
 * @n:same
 */
void remove_top(stack_t **stack, unsigned int n)
{
	stack_t *popped = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(popped);
}
/**
 * swap_2_top - swaps the tow tops of the linked list
 * @stack: same
 * @n:same
 */
void swap_2_top(stack_t **stack, unsigned int n)
{

	stack_t *bowl = (*stack)->next;

	if (!*stack || !(*stack)->next)
	{
		printf("L%d: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next = bowl->next;
	if (bowl->next)
		bowl->next->prev = *stack;
	bowl->next = *stack;
	(*stack)->prev = bowl;
	bowl->prev = NULL;
	*stack = bowl;
}
/**
 * add_2_top - adds the value of the tow tops
 * @stack: same
 * @n:same
 */
void add_2_top(stack_t **stack, unsigned int n)
{
	stack_t *bowl = (*stack)->next;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	bowl->n += (*stack)->n;
	remove_top(stack, n);
}
