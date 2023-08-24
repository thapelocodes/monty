#include "monty.h"

/**
 * spstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 */
void spstr(stack_t **head)
{
	stack_t *h = *head;

	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 * srotl- rotates the stack to the top
 * @head: stack head
 */
void srotl(stack_t **head)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
		return;
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}

/**
 * srotr- rotates the stack to the bottom
 * @head: stack head
 */
void srotr(stack_t **head)
{
	stack_t *h = *head;

	if (*head == NULL || (*head)->next == NULL)
		return;

	while (h->next)
		h = h->next;

	h->next = *head;
	h->prev->next = NULL;
	h->prev = NULL;
	(*head)->prev = h;
	(*head) = h;
}

/**
 * spchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 */
void spchar(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

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

/**
 * smod - computes the remainder of the division of the top two numbers
 * in the stack
 * @head: stack head
 * @counter: line_number
 */
void smod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	n = h->next->n % h->n;
	h->next->n = n;
	*head = h->next;
	free(h);
}
