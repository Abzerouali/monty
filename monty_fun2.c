#include "monty.h"
/**
*_add_stack - Adds the top two elements of the stack.
*@stack: A pointer to the stack.
*@line_num: The line number of the Monty instruction.
*Return: Void.
*/
void _add_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *top, *tmp;
	int sum = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	sum = top->n + top->prev->n;
	tmp = top->prev;
	top->prev = tmp->prev;
	top->n = sum;
	free(tmp);
}
/**
*_nop_stack - Does nothing; a placeholder for a no-op instruction.
*@stack: A pointer to the stack.
*@line_num: The line number of the Monty instruction.
*Return: Void.
*/
void _nop_stack(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
/**
*_sub_stack - Subtracts the top element from the second-to-top element.
*@stack: A pointer to the stack.
*@line_num: The line number of the Monty instruction.
*Return: Void.
*/
void _sub_stack(stack_t **stack, unsigned int line_num)
{
	int num1, num2;
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	num1 = (*stack)->n;
	num2 = (*stack)->prev->n;
	(*stack)->prev->n = num2 - num1;
	temp = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	free(temp);
}
/**
*_div_stack - Divides the second-to-top element by the top element.
*@stack: A pointer to the stack.
*@line_num: The line number of the Monty instruction.
*Return: Void.
*/
void _div_stack(stack_t **stack, unsigned int line_num)
{
	int num1, num2;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	num1 = (*stack)->n;
	num2 = (*stack)->prev->n;
	(*stack)->prev->n = num1 / num2;
	tmp = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	free(tmp);
}
