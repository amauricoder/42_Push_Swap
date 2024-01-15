# 2 stacks named a and b.

-stack a
contains a random amount of negative and/or positive numbers
which cannot be duplicated.

-the stack b is empty.

# OPERATIONS
- swap
-push
- rotate
-reverse rotate

SWAP
sa (SWAP A)
    swap the first 1 elements at the top of stack a.
    do nothing if there is only one or no elementes.

sb (SWAP B)
    swap the first 1 elements at the top of stack ab
    do nothing if there is only one or no elementes.

SS (Swap a and Swap b at the same time)
    sa and sb at the same time.

PUSH
pa (PUSH A)
    Take the first element at the top of b and put it at the top of a.
    do nothing if b is empty.

pb (PUSH B)
    Take the first element at the top of a and put it at the top of b.

ra (ROTATE A)
    Shift up all elemente of stack a by 1.
    the first elemente becomes the last one.

rb (ROTATE B)
    shift up all elements of stack b by 1.
    the first element becomes the last one.

rr (Rotate a and Rotate b)
    to ra and rb at the same time.

rra (reverse rotate a)
    Shift down all elements of stack a by 1.
    the last element becomes the first one.

rrb (reverse rotate b)
    shift down all elements of stack b by 1.
    the last element becomes the first one.

rrr 
    rra and rrb at the same time.


# Steps
- Create the stacks
- Implement swap, rotate, reverse rotate, push
- Choose a sort algorithm
- Plan and pseudocode
- Implement the algorithm

We can think on each node like a box with data inside, connected to next or previous box.
For this, we use a **Doubly linked list** => bi-directional.
-The head next points to the second.
-The tail next points to null.

To start, we know that we need 2 kind of information in the node.
1 - the value stored.
2 - the index of that node.

Tipes of algorithms
- The turk Algorith

# What is a stack?
- a stack of objects piled on top of each other
- has a top, and a bottom.

# DAY 2
# The turk algorithm
**What does it work?**
**concisely**
- if stack 'a' > 3
    - push 'a' node to stack 'b' twice
- until stack 'a' == 3
    push 'a' node to stack 'b', sorting 'b' in descending order
- sort three
- push all 'b' nodes back to stack 'a'
- complete with the smallest number on top

# Pseudocode
- 1 start by declaring pointer to two data structures/linked lists.
- 1.1 - one for stack 'a' and another one for stack 'a' and set them to NULL
    >Set them to NULL will avoid undefined behaviour and indicate we're starting with empty stack
- 2 - Handle imput count errors. Argument count must be 2 or more, and the second input must not be empty.

- 3 - Handle both cases of input, whethever a variable number of command line arguments, or as a string
- 3.1 - If it is a string, we need to split() to split the substrings

- 4 - Initialize stack 'a' by appending each input number as a node to stack 'a';
- 4.1 - handle integer overflow, suplicates, and syntax errors. Input must only contain digits or "+" or "-"
- 4.2 - if errors found , free stack 'a' and return error

- 5 - check for each input if is a long int
- 5.1 - if the input is a string, convert it to a long integer

- 6 - if no errors - append the nodes to stack 'a'
- 7 - check if stack are sorted, if not, implement sorting algorithm
- 8 - check for 2 numbers > if yes, just swap
- 8.1 - check for 3 numbers > if yes, sort three algorithm.
- 8.2 - if stack 'a' > 3 -> TURC Algorithm


# Useful links
-Video tutorial
    >https://www.youtube.com/watch?v=wRvipSG4Mmk

-Article about algorithm
    >https://medium.com/@ayogun/push-swap-c1f5d2d41e97

-Push Swap Visualizer
    >https://github.com/o-reo/push_swap_visualizer

- Make a Make by Nuno Jesus
    >https://github.com/Nuno-Jesus/Make-A-Make

# Useful knowledge (not of the project but its good to know)
- Rule of "right-left"


# Resume of day 1 of studyes (12/12/2023)
- Just started the studies for the how the project works. 
Looking for understanding of 
how the project works and sort algorithms.
- I saw something about the TURK ALGORITHM, but i will need to see it again tomorrow.

- For tomorrow, i need to start finish this understanding and start to work on treating of the data. Maybe, if i want, i can try to start the MAKEFILE.

# Resume of day 2 (13/12/2023)
- Leaned about the difference between break; and exit().
- Created the MAKEFILE with help. (But i need to study more my understanding of makefile and how it works, i think i have a lot of limitations concerning this concept).
- Studied more the turc algorithm. But i need to study more, because my understanding of it its not 100%.

- FOR TOMORROW -> Start to create the trating input following the pseudocode.

# Resume day 3 (14/12/2023)
- created checkers_utils.c
    inside, a function check_digits. => this function checks if the digits are numbers or spaces.

For tomorrow -> implement ft_split and work also with if argc > 2.

# Resume day 4 (16/12/2023)
- corrected checkers_utils.c.
-made the split.
- changed the name of checker_utils.c to val_functions.c
- changed the name of the function check_digits to validade_format.
- created conv_functions.c (for functions that convert units)
- created atol() inside conv_functions.
- created int	validade_nbrlimits(char **number)
- int	validade_duplication(char **number).

For next day -> Discover why this is not validating the duplicate number as expected and start to work on the memory leaks.

# Resume day 5 (17/12/2023)
- remade the first part.
- fixed the validade_format function.
- created utils_functions. This will store the utils that i need to create.
- created function ft_strcpm() inside utils_functions.c to compare value of the pointers
- fixed validade_suplication(). Now it compare the value of the strings inside the pointers.
- fixed validade_input().
- created a loop on validade_input() to check if if there any ""
**APPARENTLY, THE VALIDATIONS ARE WORKING**
- created a rule on the makefile to valgrind

For next day -> Start to study and understand lists. I need to start a stack with the data of the input.

# Resume day 6 (19/12/2023)
- nothing

# Resume day 7 (20/12/2023)
- validation done. (Needs to fix the leaks)
- start lists.
- first step (start stacks);
- created list_utils.c
- created stack_utils.c
- created t_stack_node    init_stack(char **inputs) inside of created stack_utils.c;
- created a new function t_stack_node	*ps_nodenew(int *content) to create new nodes.
- created with help of caetano the initial stack.
**NEED TO STUDY AND IMPROVE MY UNDERESTANDING OF LISTS**

# Resume day 8 (26/12/2023)
- For now, i am able to put the inputs into the stack a.


# Resume day 9 (02/01/2024)
Worked on the moves.
sa, sb, ss => DONE.
ra. rb. rr => DONE.
rra, rrb, rrr => DONE.
pa, pb => DONE.

- All moviments done. All of them tested, is seems to be of.
- Function that verify if the value of the nodes is sorted done.
 **For tomorrow, start to study how the turc algorithm works**

# Resume day 10 (03/01/2024)

- Created a function verify_sorting() that will basically verify if its sorted
- Created a function count_nodes() that will return how many nodes we have
- Created a function sort_stack() That will do the sorting operations througt other functions inside.
- Created a function sort_three() that sort 3 values.
- Created 2 funcions ls_findmin_value() and ls_findmax_value to pick the min and max value.

**FOR TOMORROW, start to study how to implement the TURC ALGORITHM to input > 3 and CHANGE THE NAME OF THE FILES FOR MORE ORGANIZATION.**

# Resume Day 11 (04/01/2024)
- Inserted Index, Price, above_med and *target to the structure,
and initialized everything with 0.
- created a function turc_algorithm()
- created funcions st_define_index() to define index and if it is
above med
- put the function st_define_index() inside of the moviments
this way, everytime a move is made we define the index automatically
-renamed all the files
**git here**
**FOR TOMORROW, create functions to calculate cost and set target**

# Resume Day 12 (05/01/2024)
- created function st_calculate_qtmov() that will lead to another 2 to define the value of the cost
- created st_define_qtmov_r() and st_define_qtmov_rr(), that will define the value of the the price depending if it is above_med or below.
- renamed st_stack_utils2.c to st_stack_definition.c
- created st_define_target() that will define the target of a to b.

**git here**
**FOR TOMORROW, Start to Sort the numbers**

# Resume Day 13 (06/01/2024)
- now i need to create a function to update all the values of st_a and st_b when called. ===> OK
- changed pa() and pb() to update the values automatically.
- changed rra() and rrb() to update values automatically.
- changed ra() and rb() to update values automatically.
- changed sa() and sb() to update values automatically.
- added a mov_ in front of the moviment functions.
- fixed a bug in st_define_qtmov_rr() -> added 2 ifs. One if index == 1 to prevent error with odd numbers and another if index == 0 to prevent error with only one number in stack_b..
- Created function srt_calc_lessmoves() that takes track of the less movs. Need to refatore because is too big.
- changed st_define_qtmov_rr() and st_define_qtmov_r() to count the moves from the target as well.

**GIT HERE**
- A lot of bugs and mistakes. HELP.
- See git log for changes.
- need to re-do calcless. is not working properly.
**GIT HERE**
- function srt_calc_lessmoves() nor working properly.
**Now, i need a function that that the cheapest node and the target on top.**

# Resume day 14 (07/01/2024)
- Re-build the srt_calc_lessmoves();
- Discovered a new bug. Updated the pb() to put every target in NULL when got there.
- Need to work in void	st_define_qtmov_r() and st_define_qtmov_rr(), they are not calculating the right quantioty of moves => I need to find a way to calculate if 2 nodes can be rrr together.
- Apparantly, everything works as expected now.
**I will need to construc a function that finds the target with biggest close value**
**GIT HERE**

# Resuma day 15 - (08/01/2024)
- still working on bugs -> apparently everything works now.
**What do I need??**
- Construct a function that finds the target with biggest close value.