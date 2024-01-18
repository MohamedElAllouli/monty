#include "monty.h"

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_1(8, ln, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * modnodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void modnodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_1(8, ln, "mod");

	if ((*stack)->n == 0)
		errors_1(9, ln);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
