#include "monty.h"

/**
* spall - function that prints everything in the stack
* @head: double head pointer to the stack
* @counter: unused line count
*
* Return: nothing
*/
void spall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
* sswap - function that swaps the top two elements of the stack
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void sswap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
