#include "monty.h"

char *op[] = {NULL, NULL, "stack", NULL};

/**
 * main - main function for monty
 * @argc: argument counter
 * @argv: array of argument strings
 * Return: success exit with failure
 */

int main(int argc, char **argv)
{
	FILE *oc;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	oc = fopen(argv[1], "r");

	if (!oc)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}

	get_op(oc);

	if (fclose(oc) != 0)
		exit(EXIT_FAILURE);
	if (op[3])
		exit(EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

/**
 * get_op - checks the file line by line for opcodes
 * @oc: file stream of the input file
 */

void get_op(FILE *oc)
{
	unsigned int line;
	int check = 0, i = 0;
	char *opcode = NULL;
	size_t oplength = 0;
	stack_t *stack = NULL;

	for (line = 1; ; line++)
	{
		check = getline(&opcode, &oplength, oc);
		if (check == EOF)
			break;
		if (check == 1)
			continue;
		for (i = 0; opcode[0] != '\0'; i++)
		{
			if (opcode[i] == '\n' || check == 1)
				break;
			if (opcode[i] == ' ' || opcode[i] == '\t')
				check = 0;
			else
				check = 1;
		}
		if (check == 0)
			continue;
		op[0] = strtok(opcode, " \n\t");
		if (!op[0])
			op[0] = strtok(NULL, " \t\n");
		if (op[0][0] == '#')
			continue;
		op[1] = strtok(NULL, " \n\t");
		execute_op(&stack, line);
		if (op[3])
			break;
	}
	if (stack)
		freeList(stack);
	if (opcode)
		free(opcode);
}

/**
 * execute_op - checks for and runs the opcode
 * @line: line number the opcode came from
 * @stack: doubly linked list of the stack
 */

void execute_op(stack_t **stack, unsigned int line)
{
	int i = 0, check = 0;

	instruction_t func_array[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}

	};

	for (i = 0; func_array[i].opcode != NULL; i++)
	{
		if (strcmp(func_array[i].opcode, op[0]) == 0)
		{
			func_array[i].f(stack, line);
			if (op[3])
				return;
			check = 1;
			break;
		}
	}

	if (check != 1)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line, op[0]);
		exit(EXIT_FAILURE);
		op[3] = "ERROR";
		return;
	}
}
