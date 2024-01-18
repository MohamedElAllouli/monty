#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}
/**
 * nodes_swaper - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void nodes_swaper(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_1(8, ln, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_1(8, ln, "add");
	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		errors_1(8, ln, "sub");


	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors_1(8, ln, "div");

	if ((*stack)->n == 0)
		errors_1(9, ln);
	(*stack) = (*stack)->next;
	s = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
