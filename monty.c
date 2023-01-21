#include "monty.h"

/**
 * main - Entry of the program monty
 * @ac: an integer representing the number of arguments passed to the program
 * @av: a double pointer to an array of strings
 * representing the arguments passed to the program
 * Return: 0
 */
int flag = 0;

int main(int ac, char **av)
{
	stack_t *stack;// initializing stack

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		error_exit(&stack);
	}
	read_file(av[1], &stack);
	free_dlistint(stack);
	return (0);
}
