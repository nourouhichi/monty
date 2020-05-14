#include "monty.h"
stack_t *stack = NULL;
/**
 * main - the main function
 * @argc: number of args
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *f;
	stack_t *roadrunner;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = openf(argv[1]);
	readf(f);
	fclose(f);
	while (stack)
        {
                roadrunner = stack;
                stack = stack->next;
                free(roadrunner);
        }
        free(stack);
	return (0);
}

/**
 * find_op - looks for the function and executes the code
 * @line: the line to be parsed
 * @n: the number of lines of the file
 */
void find_op(char *line, int n)
{
	stack_t *roadrunner, *new_node;
	int i = 0, j;
	unsigned int x;
	char *op;

	instruction_t func[] = {
		{"push", push_to_stack},
		{"pall", print_from_stack},
		{"pint", print_top},
		{"pop", remove_top},
		{"swap", swap_2_top},
		{"add", add_2_top},
		{"nop", nothing},
		{NULL, NULL}
	};
	op = strtok(line, "\t\r\n ");
	if (!op || op[0] == '#')
		return;
	if (strcmp(op, "push") == 0)
	{
		op = strtok(NULL, "\t\r\n ");
		if (!op)
		{
			fprintf(stderr, "L%d: usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}
		if (op[0] != '-')
		{
			for (j = 0; op[j] != '\0'; j++)
			{
				if (isdigit(op[j]) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", n);
					exit(EXIT_FAILURE); }
			}
		}
		x = atoi(op);
		new_node = malloc(sizeof(stack_t));
	        if (!new_node)
        	{
                	fprintf(stderr, "Error: malloc failed\n");
                	free(new_node);
                	exit(EXIT_FAILURE);
        	}
        	new_node->n = x;
        	new_node->prev = NULL;
		func[0].f(&new_node, n);
		return; }
	for (i = 0; func[i].opcode; i++)
	{
		if (strcmp(op, func[i].opcode) == 0)
		{
			func[i].f(&stack, n);
			return; }
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", n, op);
	while (stack)
	{
		roadrunner = stack;
		stack = stack->next;
		free(roadrunner);
	}
	free(stack);
	exit(EXIT_FAILURE);

}
/**
 * push_to_stack - pushes nodes to the stack
 * @stack:same
 * @n:same
 */
void push_to_stack(stack_t **new_node, unsigned int n)
{
	(void) n;
	if (!stack)
	{
		(*new_node)->next = NULL;
		stack = *new_node;
	}
	else
	{
		(*new_node)->next = stack;
		stack->prev = *new_node;
		stack = *new_node;
	}
}
