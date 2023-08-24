#include "monty.h"

/**
 * spall - prints the stack
 * @head: stack head
 */
void spall(stack_t **head)
{
	stack_t *h = *head;

	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * spint - prints the top
 * @head: stack head
 * @counter: line_number
 */
void spint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{ fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	printf("%d\n", (*head)->n);
}

/**
 * spop - prints the top
 * @head: stack head
 * @counter: line_number
 */
void spop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{ fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(info.file);
		free(info.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	h = *head;
	*head = h->next;
	free(h);
}

/**
 * sswap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 */
void sswap(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	int len = 0, n;

	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	n = h->n;
	h->n = h->next->n;
	h->next->n = n;
}

/**
 * spush - add node to the stack
 * @head: stack head
 * @counter: line_number
 */
void spush(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			j++;
		for (; info.arg[j] != '\0'; j++)
			if (info.arg[j] > 57 || info.arg[j] < 48)
				flag = 1;
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
	n = atoi(info.arg);
	if (info.lifi == 0)
		add_st(head, n);
	else
		add_q(head, n);
}
