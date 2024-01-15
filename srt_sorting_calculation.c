/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_sorting_calculation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:18:52 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/10 14:43:15 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate the node with less moves to put on top.
//have in consideration the lower index.
t_stack	*srt_calc_lessmoves(t_stack **stack_a)
{
	t_stack *temp_a;
	t_stack	*selected_node;
	int		index;
	int		min_qtmoves;
	
	temp_a = *stack_a;
	selected_node = NULL;
	index = INT_MAX;
	min_qtmoves = INT_MAX;
	while (temp_a != NULL)
	{
		if (temp_a->index < index || temp_a->qt_mov_top < min_qtmoves)
		{
			min_qtmoves = temp_a->qt_mov_top;
			index = temp_a->index;
			selected_node = temp_a;
		}
		temp_a = temp_a->next;
	}
	return (selected_node);
}
//Calculate the quantity of moves its needed to put the nodes on top
//have in consideration the target node.
void	st_calculate_qtmov(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;
	int	size_b;
	t_stack	*temp;

	size_a = st_nodes_counter(stack_a);
	size_b = st_nodes_counter(stack_b);
	temp = *stack_a;
	while (temp)
	{
		temp->qt_mov_top = temp->index;
		if (temp->above_med == 0)
			temp->qt_mov_top = size_a - (temp->index);
		if (temp->target->above_med == 1)
			temp->qt_mov_top += temp->target->index;
		else
			temp->qt_mov_top += size_b - (temp->target->index);
		temp = temp->next;
	}
}
//Find the max value on a list and return it.
int	st_findmax_value(t_stack **stack)
{
	int		max;
	t_stack	*temp;

	if (!*stack)
		return (-1);
	temp = *stack;
	max = temp->value;
	while (temp != NULL)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}
//Find the min value on a list and return it.
int	st_findmin_value(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	if (!*stack)
		return (-1);
	temp = *stack;
	min = temp->value;
	while (temp != NULL)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}
