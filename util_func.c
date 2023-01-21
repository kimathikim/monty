#include "monty.h"
/**
 * errro_exit - If the pointer passed to the function is not NULL, 
 * it calls the free_dlistint function, which frees the memory allocated for each node in the stack.
 * Exits the program with the status EXIT_FAILURE.
 *
 * @stack: pointer to the head of the stack
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * isnumber - checks if the string represent a number
 * @str: string being passed
 *
 * Return: returns 1 is the string is a number and 0 if its not
 */
int isnumber(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/**
 * _rotl - performs a left rotation on the elemtent of in the stack, it does this by:
 *
 * @stack: pointer to the top of the stack
 * @__attribute__ ((unused)): to tell the compiler that the line_number argument is not used,
 * this is used to suppress the warning from the compiler.
 * @linenumber: the index of the current line
 */
void _rotl(stack_t **stack,  __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;
	int temp1, temp2;

	if (*stack == NULL)
		return;
	runner = *stack;

	while (runner->next)
		runner = runner->next;
	while (runner)
	{
		if (!runner->next)
		{
			temp1 = runner->n;
			runner->n = (*stack)->n;
		}
		else
		{
			temp2 = runner->n;
			runner->n = temp1;
			temp1 = temp2;
		}
		runner = runner->prev;
	}
}

/**
 * _rotr - performs  a right rotation on the elements of the stack, it does this by:
 *
 *  @ __attribute__ ((unused)): to tell the compiler that the line_number argument is not used
 */
void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner1, *runner2;
	int temp1, temp2;

	if (*stack == NULL)
		return;

	runner1 = *stack;
	runner2 = *stack;

	while (runner1->next)
	{
		runner1 = runner1->next;
	}
	while (runner2)
	{
		if (runner2->prev == NULL)
		{
			temp1 = runner2->n;
			runner2->n = runner1->n;
		}
		else
		{
			temp2 = runner2->n;
			runner2->n = temp1;
			temp1 = temp2;
		}
		runner2 = runner2->next;
	}
}
