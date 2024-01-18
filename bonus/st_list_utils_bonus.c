/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_list_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:35:14 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/18 14:14:41 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//Create a new node with the value of the input
//initialize all other values with 0 or NULL.
t_stack	*st_newitem(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->qt_mov_top = 0;
	new->above_med = 0;
	new->target = NULL;
	new->next = NULL;
	return (new);
}

//Add a node to the end of the list.
void	st_item_addback(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (!temp)
		*lst = new;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

//Free all nodes of a list
void	st_list_free(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	st_putmax_ontop(t_stack **stack)
{
	t_stack	*max_node;
	t_stack	*temp;
	int		max_node_index;
	int		stack_size;
	int		times;

	max_node = st_findbigger_node(stack);
	max_node_index = max_node->index;
	stack_size = st_nodes_counter(stack);
	times = stack_size - max_node_index;
	temp = *stack;
	while (max_node->above_med == 1 && max_node_index > 0)
	{
		mov_rb(stack, 0);
		max_node_index --;
	}
	while (max_node->above_med == 0 && times > 0)
	{
		mov_rrb(stack, 0);
		times --;
	}
}

void	st_putmin_ontop(t_stack **stack)
{
	t_stack	*min_node;
	t_stack	*temp;
	int		min_node_index;
	int		stack_size;
	int		times;

	min_node = st_findlower_node(stack);
	min_node_index = min_node->index;
	stack_size = st_nodes_counter(stack);
	times = stack_size - min_node_index;
	temp = *stack;
	while (min_node->above_med == 1 && min_node_index > 0)
	{
		mov_ra(stack, 0);
		min_node_index --;
	}
	while (min_node->above_med == 0 && times > 0)
	{
		mov_rra(stack, 0);
		times --;
	}
}
