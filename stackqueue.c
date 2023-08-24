#include "monty.h"

/**
 * add_st - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 */
void add_st(stack_t **head, int n)
{

	stack_t *new, *h;

	h = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{ printf("Error\n");
		exit(0); }
	if (h)
		h->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}

/**
 * add_q - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 */
void add_q(stack_t **head, int n)
{
	stack_t *h = *head, *new = malloc(sizeof(stack_t));

	if (new == NULL)
		printf("Error: malloc failed\n");

	new->n = n;
	new->next = NULL;
	if (h)
		while (h->next)
			h = h->next;
	if (!h)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		h->next = new;
		new->prev = h;
	}
}

/**
* sfree - frees a doubly linked list
* @head: head of the stack
*/
void sfree(stack_t *head)
{
	stack_t *h;

	while (head)
	{
		h = head->next;
		free(head);
		head = h;
	}
}
