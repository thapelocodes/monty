#include "monty.h"

/**
* sadd - function that adds the top two elements of the stack
* @head: double pointer head to the stack
* @counter: line count
*
* Return: nothing
*/
void sadd(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
* ssub - function that substracts nodes
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void ssub(stack_t **head, unsigned int counter)
{
	stack_t *temp;
	int sub, nd;

	temp = *head;
	for (nd = 0; temp != NULL; nd++)
		temp = temp->next;
	if (nd < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}

/**
* smul - function that multiplies the top two elements of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void smul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(info.file);
		free(info.content);
		sfree(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->next->n * h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
* sdiv - function that divides the top two elements of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void sdiv(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
	temp = h->next->n / h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}

/**
* smod - function that computes the remainder of the division of the second
* top element of the stack by the top element of the stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void smod(stack_t **head, unsigned int counter)
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
	temp = h->next->n % h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
