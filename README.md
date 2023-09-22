0x19. C - Stacks, Queues - LIFO, FIFO

Learning Objectives

General
-What do LIFO and FIFO mean
-What is a stack, and when to use it
-What is a queue, and when to use it
-What are the common implementations of stacks and queues
-What are the most common use cases of stacks and queues
-What is the proper way to use global variables


# Monty Stack-Based Calculator

## Description

This is a simple stack-based calculator program written in C that interprets and executes Monty programming language instructions. Monty is a minimalistic stack-based programming language where operations are performed on a stack data structure.

The program includes various stack manipulation operations such as push, pop, add, subtract, divide, and more. It reads Monty script files and processes the instructions specified in those files.

## How to Use

To use this Monty interpreter, follow these steps:

1. **Compilation**: Compile the program using a C compiler (e.g., gcc):

   ```bash
   $ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

