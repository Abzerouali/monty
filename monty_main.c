#include "monty.h"
store_t command;
/**
*_create_node - Creates a new node for the stack.
*@data: The integer data to be stored in the node.
*Return: A pointer to the newly created node.
*/
stack_t *_create_node(int data)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->n = data;
	node->next = NULL;
	return (node);
}
/**
*_slaughter_line - Tokenizes the input line and extracts data for commands.
*@line: The input line.
*Return: Void.
*/
void _slaughter_line(char *line)
{
	command.data = strtok(line, " ");
	if (strcmp(command.data, "push") == 0)
	{
		command.val = strtok(NULL, " ");
	}
}
/**
*_free_dlistint - Frees a doubly linked list.
*@head: A pointer to the head of the list.
*Return: Void.
*/
void _free_dlistint(stack_t *head)
{
	stack_t *p;

	while (head != NULL)
	{
		p = head;
		head = head->prev;
		free(p);
	}
	free(head);
}
/**
*_check_number - Checks if a string represents a valid integer.
*Return: 1 if the string is a valid integer, 0 otherwise.
*/
int _check_number(void)
{
	int _check_number;
	int j;

	j = 0;
	while (command.val[j] != '\0')
	{
		if ((command.val[j] >= 48 && command.val[j] <= 57) || command.val[j] == '-')
		{
			_check_number = 1;
			j++;
		}
		else
		{
			_check_number = 0;
			break;
		}
		j++;
	}
	return (_check_number);
}
/**
*_error - Displays an error message and exits the program.
*@f: A file pointer.
*@top: A pointer to the top of the stack.
*@lineNumber: The line number of the error.
*@errorStr: The error message.
*Return: Void.
*/
void _error(FILE *f, stack_t *top, int lineNumber, char *errorStr)
{
	fprintf(stderr, "L%u: %s", lineNumber, errorStr);
	_free_dlistint(top);
	fclose(f);
	exit(EXIT_FAILURE);
}
/**
*_read_line - Reads lines from a file and interprets Monty bytecode.
*@f: A file pointer.
*@Dictionnary: An array of instruction definitions.
*Return: Void.
*/
void _read_line(FILE *f, instruction_t *Dictionnary)
{
	stack_t *top = NULL;
	char line[100], *noSpace;
	unsigned int lineNumber = 0;
	int checkNum, i = 0;

	while (fgets(line, sizeof(line), f))
	{
		command.val = NULL;
		lineNumber++;
		line[strcspn(line, "\n")] = '\0';
		noSpace = line;
		while (*noSpace == ' ')
			noSpace++;
		if (*noSpace != '\0' && *noSpace != '#')
		{
			_slaughter_line(noSpace);
			i = 0;
			while (Dictionnary[i].opcode != NULL)
			{
				if (strcmp(command.data, Dictionnary[i].opcode) == 0)
				{
					if (strcmp(command.data, "push") == 0)
					{
						if (command.val == NULL)
							_error(f, top, lineNumber, "usage: push integer");
						checkNum = _check_number();
						if (checkNum == 1)
						{
							command.number = atoi(command.val);
							Dictionnary[i].f(&top, lineNumber);
							break;
						}
						else
							_error(f, top, lineNumber, "usage: push integer");
					}
					else
					{
						Dictionnary[i].f(&top, lineNumber);
						break;
					}
				}
				i++;
			}
		}
		if (Dictionnary[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					lineNumber, command.data);
			_free_dlistint(top);
			fclose(f);
			exit(EXIT_FAILURE);
		}
	}
	_free_dlistint(top);
}
/**
*main - The entry point of the Monty interpreter.
*@argc: The number of command-line arguments.
*@argv: An array of command-line arguments.
*Return: 0 on success, EXIT_FAILURE on failure.
*/
int main(int argc, char *argv[])
{
	instruction_t Dictionnary[] = {
		{"push", _push_node},
		{"pall", _pall_stack},
		{"pint", _pint_stack},
		{"pop", _pop_stack},
		{"swap", _swap_stack},
		{"add", _add_stack},
		{"nop", _nop_stack},
		{"sub", _sub_stack},
		{"div", _div_stack},
		{NULL, NULL}};
	FILE *f;

	if (argc != 2)
	{
		perror("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file '%s': ", argv[1]);
		exit(EXIT_FAILURE);
	}
	_read_line(f, Dictionnary);
	fclose(f);
	return (0);
}
