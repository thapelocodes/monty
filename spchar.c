#include "monty.h"

/**
* spchar - function that prints the char at the top of the stack,
* followed by a new line
* @head: stack head
* @counter: line count
*
* Return: nothing
*/
void spchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
