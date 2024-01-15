/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:38:08 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/06 18:19:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//st_init_stack() inicializes a new stack with the values of argv.
t_stack	*st_init_stack(char **argv)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	i = 0;
	while (argv[i] != (void *)0)
	{
		new_node = st_newitem(ft_atol(argv[i]));
		st_item_addback(&stack, new_node);
		i ++;
	}
	return (stack);
}

//st_printstack() prints all the values of the nodes in the list
void	st_printstack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("Value => %i ", stack->value);
		ft_printf("Index => %i ", stack->index);
		ft_printf("Qt_mov_top => %i ", stack->qt_mov_top);
		ft_printf("Above Med => %i ", stack->above_med);
		if (stack->target != NULL)
			ft_printf("Target => %i\n", stack->target->value);
		else
			ft_printf("Target => NULL\n");
		stack = stack->next;
	}
}

//count how many nodes exists. Return the number of nodes.
int	st_nodes_counter(t_stack **stack)
{
	int		counter;
	t_stack	*temp;

	temp = *stack;
	counter = 0;
	if (*stack == NULL)
		return (0);
	while (temp != NULL)
	{
		counter ++;
		temp = temp->next;
	}
	return (counter);
}

//find the node with the bigger value and return a pointer to it
t_stack	*st_findbigger_node(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*bigger_node;
	int		max_value;

	temp = *stack;
	bigger_node = NULL;
	max_value = INT_MIN;
	while (temp != NULL)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
			bigger_node = temp;
		}
		temp = temp->next;
	}
	return (bigger_node);
}
//Isolated test to st_init_stack();
/* 
int main(void)
{
	char *test[] = {"1", "2", "3", NULL};
	t_stack *stack_test;

	stack_test = st_init_stack(test);
	while (stack_test != NULL)
	{
		t_stack *temp = stack_test->next; // Save the next pointer
		ft_printf("%i\n", stack_test->value);
		free(stack_test);                 // Free the current node
		stack_test = temp;                // Move to the next node
	}
	return 0;
}*/

//isolated test to st_nodes_counter();
/* int main(void)
{
	t_stack *stack = NULL;
	t_stack *node;
	
	int i = 1;
	while (i <= 13)
	{
		node = st_newitem(i);
		st_item_addback(&stack, node);
		i ++;
	}
	ft_printf("TEST VERIFY SORTING => %i", st_nodes_counter(&stack));
} */
