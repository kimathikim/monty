#include "monty.h"

/**
 * _push - push an integer to the stack. It does this by:
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int push_arg;

	push_arg = 0;
	new = malloc(sizeof(stack_t));

	if (!new)
	{
		printf("Error: malloc function failed\n");
		error_exit(stack);
	}

	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		printf("L%d: usage: push inetger'n", line_number);
		error_exit(stack);
	}

	if (sq_flag == 1)
	{
		add_dnodeint_end(stack, push_arg);
	}

	if (sq_flag == 0)
	{
		add_dnodeint(stack, push_arg);
	}
}


/**
 * _pall - print all element in the stack lati oke de ile
 * @stack: a pointer to a linked list stack
 * @line_number: an unsigned integer representing the line number of the
*/

void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - print the integer at the top of stack ONLY
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occures on
 *
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;

	runner = *stack;

	if (runner == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		error_exit(stack);
	}
	printf("%d\n", runner->n);
}


/**
 * _swap - swap the element in the top of stack with the n in the second stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}


/**
 * _pop - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		error_exit(stack);
	}
	delete_dnodeint_at_index(stack, 0);
}
