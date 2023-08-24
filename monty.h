#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - information structure for monty file executions.
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct info_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} info_t;

extern info_t info;

/* opcode.c */
void spush(stack_t **head, unsigned int number);
void spall(stack_t **head);
void spint(stack_t **head, unsigned int number);
void spop(stack_t **head, unsigned int counter);
void sswap(stack_t **head, unsigned int counter);

/* opcode1.c */
void sadd(stack_t **head, unsigned int counter);
void snop(stack_t **head, unsigned int counter);
void ssub(stack_t **head, unsigned int counter);
void sdiv(stack_t **head, unsigned int counter);
void smul(stack_t **head, unsigned int counter);

/* opcode2.c */
void smod(stack_t **head, unsigned int counter);
void spchar(stack_t **head, unsigned int counter);
void spstr(stack_t **head);
void srotl(stack_t **head);
void srotr(stack_t **head);

/* opcode3.c */
void squeue(void);
void sstack(void);

/* stackqueue.c */
void add_st(stack_t **head, int n);
void add_q(stack_t **head, int n);
void sfree(stack_t *head);

/* monty.c */
char *realloc_(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clr_line(char *content);
int exec(char *content, stack_t **head, unsigned int counter, FILE *file);

#endif
