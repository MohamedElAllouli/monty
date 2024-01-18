#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void fileopen(char *file_name);
int parseline(char *buffer, int line_number, int format);
void fileread(FILE *);
int charlen(FILE *);
void funcfind(char *, char *, int, int);
/*Stack operations*/
stack_t *node_creater(int n);
void free_nodes(void);
void stack_printer(stack_t **, unsigned int);
void add_at_stack(stack_t **, unsigned int);
void add_at_queue(stack_t **, unsigned int);
void fun_call(op_func, char *, char *, int, int);
void top_printer(stack_t **, unsigned int);
void top_poper(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void nodes_swaper(stack_t **, unsigned int);
/*Math operations with nodes*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void modnodes(stack_t **, unsigned int);
/*String operations*/
void printchar(stack_t **, unsigned int);
void _printstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
/*Error hanlding*/
void errors(int error_code, ...);
void errors_1(int error_code, ...);
void _stringerrors(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
