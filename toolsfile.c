#include "monty.h"

/**
 * fileopen - open a file
 * @file_name: the file namepath
 * Return: void
 */
void fileopen(char *file_name)
{
	FILE *f = fopen(file_name, "r");

	if (file_name == NULL || f == NULL)
		errors(2, file_name);
	fileread(f);
	fclose(f);
}

/**
 * fileread - reads a file
 * @f: pointer to file descriptor
 * Return: void
 */
void fileread(FILE *f)
{
	int ln, frmt = 0;
	char *b = NULL;
	size_t l = 0;

	for (ln = 1; getline(&b, &l, f) != -1; ln++)
	{
		frmt = parseline(b, ln, frmt);
	}
	free(b);
}

/**
 * parseline - Separates each line into tokens to determine
 * @b: line from the file
 * @ln: line number
 * @frmt:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parseline(char *b, int ln, int frmt)
{
	char *op, *v;
	const char *de = "\n ";

	if (b == NULL)
		errors(4);

	op = strtok(b, de);
	if (op == NULL)
		return (frmt);
	v = strtok(NULL, de);
	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);
	funcfind(op, v, ln, frmt);
	return (frmt);
}
/**
 * funcfind - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void funcfind(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_at_stack},
		{"pall", stack_printer},
		{"pint", top_printer},
		{"pop", top_poper},
		{"nop", nop},
		{"swap", nodes_swaper},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", modnodes},
		{"pchar", printchar},
		{"pstr", _printstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			fun_call(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, ln, opcode);
}

/**
 * fun_call- Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @v: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @fmt: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void fun_call(op_func func, char *op, char *v, int ln, int fmt)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (v != NULL && v[0] == '-')
		{
			v = v + 1;
			flag = -1;
		}
		if (v == NULL)
			errors(5, ln);
		for (i = 0; v[i] != '\0'; i++)
		{
			if (isdigit(v[i]) == 0)
				errors(5, ln);
		}
		node = node_creater(atoi(v) * flag);
		if (fmt == 0)
			func(&node, ln);
		if (fmt == 1)
			add_at_queue(&node, ln);
	}
	else
		func(&head, ln);
}
