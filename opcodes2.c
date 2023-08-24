#include "monty.h"

/**
* spop - function that prints the top of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void spop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
* spint - function that prints the top of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void spint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* snop - function that does nothing
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void snop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
