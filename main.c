#include "monty.h"

info_t info = {NULL, NULL, NULL, 0};

/**
* main - function for monty code interpreter
* @argc: argument count
* @argv: argument value
*
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t rline = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	info.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rline > 0)
	{
		content = NULL;
		rline = getline(&content, &size, file);
		info.content = content;
		counter++;
		if (rline > 0)
		{
			exec(content, &stack, counter, file);
		}
		free(content);
	}
	sfree(stack);
	fclose(file);
return (0);
}
