#include "monty.h"

/**
 * snop - nothing
 * @head: stack head
 * @counter: line_number
 */
void snop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 * ssub- subtraction
 * @head: stack head
 * @counter: line number
 */
void ssub(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	int n, i;

	for (i = 0; h != NULL; i++)
		h = h->next;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	n = aux->next->n - aux->n;
	h->next->n = n;
	*head = h->next;
	free(h);
}

/**
 * smul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 */
void smul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	n = h->next->n * h->n;
	h->next->n = n;
	*head = h->next;
	free(h);
}

/**
 * sadd - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 */
void sadd(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	n = h->n + h->next->n;
	h->next->n = n;
	*head = h->next;
	free(h);
}

/**
 * sdiv - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 */
void sdiv(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	int len = 0, n;

	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{ fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE); }
	h = *head;
	if (h->n == 0)
	{ fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE); }
	n = h->next->n / h->n;
	h->next->n = n;
	*head = h->next;
	free(h);
}
