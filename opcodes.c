#include "monty.h"

/**
* spush - function that adds node to the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void spush(stack_t **head, unsigned int counter)
{
	int i, m = 0, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			m++;
		for (; info.arg[m] != '\0'; m++)
		{
			if (info.arg[m] > 57 || info.arg[m] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(info.file);
			free(info.content);
			sfree(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE); }
	i = atoi(info.arg);
	if (info.lifi == 0)
		addnode(head, i);
	else
		add_q(head, i);
}
