#include "monty.h"
/**
*_push_node - Pushes an integer onto the stack.
*@stack: A pointer to the stack.
*@line_num: The line number of the Monty instruction.
*Return: void.
*/
void _push_node(stack_t **stack, unsigned int line_num)
{
	stack_t *node;
	(void)line_num;

	node = _create_node(command.number);
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
		return;
	}
	node->prev = *stack;
	(*stack)->next = node;
	*stack = node;
}
/**
*_pall_stack - Prints all the values on the stack.
*@stack: A pointer to the stack.
*@line_num: The line number of the Monty instruction.
*Return: void.
*/
void _pall_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
/**
*_pint_stack - Prints the value at the top of the stack.
*@stack: A pointer to the stack.
*@line_num: The line number of the Monty instruction.
*Return: void.
*/
void _pint_stack(stack_t **stack, unsigned int line_num)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
}
/**
*_pop_stack - Removes the top element from the stack.
*@stack: first variable
*@line_num: Second variable
*Return: void.
*/
void _pop_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *pop;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	pop = *stack;
	*stack = (*stack)->prev;
	free(pop);
}
/**
*_swap_stack - Swaps the top two elements on the stack.
*@stack: first variable
*@line_num: Second variable
*Return: void.
*/
void _swap_stack(stack_t **stack, unsigned int line_num)
{
	int tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = tmp;
}
