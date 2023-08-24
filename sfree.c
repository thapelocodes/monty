#include "monty.h"

/**
* sfree - function that frees a doubly linked list
* @head: head pointer to the stack
*
* Return: nothing
*/
void sfree(stack_t *head)
{
	stack_t *h;

	h = head;
	while (head)
	{
		h = head->next;
		free(head);
		head = h;
	}
}

/**
* sstack - function that prints the top
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void sstack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	info.lifi = 0;
}
