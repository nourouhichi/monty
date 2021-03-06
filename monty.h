#ifndef MONTY
#define MONTY
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/* main functions*/
int main(int argc, char **argv);
FILE *openf(char *filen);
void readf(FILE *f);
void find_op(char *line, int n);
void printer(char *op, int n);
/*opcode functions*/
void push_to_stack(stack_t **new_node, unsigned int n);
void print_from_stack(stack_t **stack, unsigned int n);
void print_top(stack_t **stack, unsigned int n);
void remove_top(stack_t **stack, unsigned int n);
void swap_2_top(stack_t **stack, unsigned int n);
void add_2_top(stack_t **stack, unsigned int n);
void nothing(stack_t **stack, unsigned int n);
void sub(stack_t **stack, unsigned int n);
void divi(stack_t **stack, unsigned int n);
void mult(stack_t **stack, unsigned int n);
void modu(stack_t **stack, unsigned int n);
void pchar(stack_t **stack, unsigned int n);
void pstr(stack_t **stack, unsigned int n);
void rotl(stack_t **stack, unsigned int n);
#endif
