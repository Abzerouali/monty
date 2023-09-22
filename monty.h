#ifndef LIST_MONTY_H
#define LIST_MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
/**
*struct stack_s - doubly linked list representation of a stack.
*@n: int
*@prev: points to the previous element of the stack.
*@next: points to the next element of the stack.
*Description: doubly linked list node structure.
*for stack, queues, LIFO, FIFO.
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
*struct instruction_s - opcode and its function.
*@opcode: the opcode.
*@f: function to handle the opcode.
*Description: opcode and its function.
*for stack, queues, LIFO, FIFO.
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;
/**
*struct store_s - checker.
*@data: data.
*@val: val.
*@number: number.
*Description: store_t.
*for stack, queues, LIFO, FIFO.
*/
typedef struct store_s
{
	char *data;
	char *val;
	int number;
} store_t;
extern store_t command;


void _push_node(stack_t **stack, unsigned int  line_num);
void _pall_stack(stack_t **stack, unsigned int line_num);
void _pint_stack(stack_t **stack, unsigned int line_num);
void _pop_stack(stack_t **stack, unsigned int line_num);
stack_t *_create_node(int data);
void _slaughter_line(char *line);
void _free_dlistint(stack_t *head);
void _read_line(FILE *f, instruction_t *Dictionnary);
int _check_number();
void _error(FILE *f, stack_t *top, int lineNumber, char *errorStr);
void _swap_stack(stack_t **stack, unsigned int line_num);
void _add_stack(stack_t **stack, unsigned int line_num);
void _nop_stack(stack_t **stack, unsigned int line_num);
void _sub_stack(stack_t **stack, unsigned int line_num);
void _div_stack(stack_t **stack, unsigned int line_num);
#endif
