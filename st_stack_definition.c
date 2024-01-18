/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_stack_definition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:26:17 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/18 08:31:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Defines the index and above_med.
//If is above_med -> 1 -> If is below -> 0;
void	st_define_index(t_stack **stack)
{
	t_stack	*temp;
	int		new_index;
	int		list_size;

	list_size = st_nodes_counter(stack);
	temp = *stack;
	new_index = 0;
	while (temp != NULL)
	{
		if (new_index > list_size / 2)
			temp->above_med = 0;
		else
			temp->above_med = 1;
		temp->index = new_index;
		new_index ++;
		temp = temp->next;
	}
}

// the target must be the node with the lowest close value possible
// if there is no lowest close value possible, then it's the maximum
void	st_define_lower_target(t_stack **stack_a, t_stack **stack_b)
{
	long	lowest_value;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	while (temp_a != NULL)
	{
		temp_b = *stack_b;
		lowest_value = -2147483649;
		while (temp_b != NULL)
		{
			if (temp_a->value > temp_b->value && lowest_value < temp_b->value)
			{
				lowest_value = temp_b->value;
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (lowest_value == -2147483649)
			temp_a->target = st_findbigger_node(stack_b);
		temp_a = temp_a->next;
	}
}

// the target must be the node with the biggest close value possible
// if there is no biggest close value possible, then it's the min
void	st_define_bigger_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current_a;
	t_stack		*temp_b;
	long		biggest_value;

	temp_b = *stack_b;
	while (temp_b)
	{
		biggest_value = 2147483648;
		current_a = *stack_a;
		while (current_a)
		{
			if (current_a->value > temp_b->value 
				&& biggest_value > current_a->value)
			{
				biggest_value = current_a->value;
				temp_b->target = current_a;
			}
			current_a = current_a->next;
		}
		if (biggest_value == 2147483648)
			temp_b->target = st_findlower_node(stack_a);
		temp_b = temp_b->next;
	}
}

//define qt_mov to top
void	st_update_b_values(t_stack **stack_a, t_stack **stack_b)
{
	st_define_index(stack_b);
	st_define_bigger_target(stack_a, stack_b);
}

void	st_update_a_values(t_stack **stack_a, t_stack **stack_b)
{
	st_define_index(stack_a);
	st_define_lower_target(stack_a, stack_b);
	st_calc_qtmov(stack_a, stack_b);
}
