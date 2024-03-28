/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:38:08 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/22 09:39:37 by aconceic         ###   ########.fr       */
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
void	st_printstack(t_stack *stack, char stack_letter)
{
	if (stack_letter == 'a')
		ft_printf("STACK A \n");
	else if (stack_letter == 'b')
		ft_printf("STACK B \n");
	if (stack != NULL)
	{
		while (stack != NULL)
		{
			ft_printf("=> %i \n", stack->value);
			stack = stack->next;
		}
	}
	else
		ft_printf("EMPTY \n");
	ft_printf("\n");
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

t_stack	*st_findlower_node(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*lower_node;
	int		max_value;

	if (stack == NULL)
		return (NULL);
	temp = *stack;
	lower_node = NULL;
	max_value = INT_MAX;
	while (temp != NULL)
	{
		if (temp->value < max_value)
		{
			max_value = temp->value;
			lower_node = temp;
		}
		temp = temp->next;
	}
	return (lower_node);
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
