# Push_Swap
![Banner](push_swap.gif "ft_printf banner") <br>
"This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed it's necessary to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting."

## Table of contents
- [Introduction](#introduction)
- [Usage](#usage)
- [Sorting Algorithm](#sorting-algorithm)
- [Makefile Overview](#makefile-overview)
- [License and Thoughtful Advice](#license-and-thoughtful-advice)

## Introduction
The Push Swap project presents a simple yet essential algorithmic task: sorting data efficiently. In this project, we work with a collection of integer values, two stacks, and a set of instructions to manipulate these stacks. Our objective is to develop a C program named push_swap that determines and outputs the shortest sequence of Push Swap language instructions required to sort the given integers.
>The code was written according to the 42 norm guidelines(norminette)

## Usage
1. On your terminal, clone the repository
```bash
git clone git@github.com:amauricoder/42_Push_Swap.git
```
2. Do make to compile the files
```bash
make
```
This will generate a push_swap file in the root folder, this is the executable of the program.

3. Run the program with the numbers you want as parameters
``` bash
./push_swap 5 -10 13
```
This will return the moviments necessary to organize the stack.
To know more about the rules for moviments, see [Subject](subject) <br>

## Sorting algorithm
This code was written based on an article by **A. Yigit Ogun**. Click [Here](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) if you want to check it out.<br>
A. Yigit Ogun called this "The Turc Algorithm". Essentially, he determines the optimal sequence of moves required to arrange a set of numbers in order, and then performs the sorting accordingly. This method prioritizes efficiency by minimizing the number of moves needed to put the stack in order.
### How does "The Turc Algorithm" works ??
First of all: for the turc algorithm to work we need to have more than 3 numbers on the stack. If we have 3 numbers only, we use a simple sort three algorithm, that is based on all the exiting possibilities to sort 3 numbers. If we have only 2 numbers, then we use a simple "sa", that changes the position of the first and second number of stack a. <br>Again, to know more about the moviments and the rules, please check [Subject](subject). <br>
If we have more than 3 numbers, the turc algorithm takes action.
Explaining in a very simple and direct form how it works:<br>
  - Transfer all elements from STACK_A to STACK_B in descending order. This rearrangement is intended to facilitate automatic sorting when the elements are subsequently pushed back to STACK_A.
  - We perform the transfer from STACK_A to STACK_B until STACK A contains only three numbers.
  - When STACK_A is only with the 3 numbers, we perform a sort three algorithm on STACK_A and send the numbers of STACK_B back to STACK_A.

For a more detailed explanation, I highly recommend for you too read the article [Here](https://medium.com/@ayogun/push-swap-c1f5d2d41e97). <br>
Below, there is an illustration of how this algorithm works. <br>
<!-- FOTO PS VISUALIZER AQUI -->
If you want to test the program like this, check the [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer).

## Makefile Overview

In this project, the Makefile offers the following essential rules:
- **make**: Compiles the project to libftprintf.a.
- **make clean**: Cleans the directory by removing `.o` files, preserving `libftprintf.a`.
- **make fclean**: Completely cleans the directory by deleting both `.o` files and `libftprintf.a`.
- **make re**: Refreshes `libftprintf.a` by recompiling everything.

## License and Thoughtful Advice
[View License](LICENSE)

Stop deceiving yourself. 
Mere ability to copy code doesn't enhance your skills. This is outside the scope of school purposes. 
Everyone can be a "copy paster," but not everyone can be a programmer. Good luck!
