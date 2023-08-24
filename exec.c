#include "monty.h"

/**
 * exec - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 *
 * Return: 1 on success, otherwise 0
 */
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t ops[] = { {"push", spush}, {"pall", spall},
				{"pint", spint}, {"pop", spop},
				{"swap", sswap}, {"add", sadd},
				{"nop", snop}, {"sub", ssub},
				{"div", sdiv}, {"mul", smul},
				{"mod", smod}, {"pchar", spchar},
				{"pstr", spstr}, {"rotl", srotl},
				{"rotr", srotr}, {"queue", squeue},
				{"stack", sstack}, {NULL, NULL} };
	unsigned int i = 0;
	char *op = strtok(content, " \n\t");

	if (op && op[0] == '#')
		return (0);

	info.arg = strtok(NULL, " \n\t");
	while (ops[i].opcode && op)
		if (strcmp(op, ops[i].opcode) == 0)
		{ ops[i++].f(stack, counter);
			return (0); }

	if (op && ops[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		sfree(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
