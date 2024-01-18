#include "monty.h"

/**
 * printchar - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void printchar(stack_t **stack, unsigned int ln)
{
	int asc;

	if (stack == NULL || *stack == NULL)
		_stringerrors(11, ln);
	asc = (*stack)->n;
	if (asc < 0 || asc > 127)
		_stringerrors(10, ln);
	printf("%c\n", asc);
}
/**
 * _printstr - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _printstr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asc;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		asc = tmp->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
