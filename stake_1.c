#include "monty.h"


/**
 * add_at_stack - Adds a node to the stack.
 * @new: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_at_stack(stack_t **new, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tmp = head;
	head = *new;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * stack_printer - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: line number of  the opcode.
 */
void stack_printer(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	(void) ln;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * top_poper - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void top_poper(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		errors_1(7, ln);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * top_printer - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void top_printer(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		errors_1(6, ln);
	printf("%d\n", (*stack)->n);
}
