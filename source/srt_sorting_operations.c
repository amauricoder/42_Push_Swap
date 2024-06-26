/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_sorting_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:35:45 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/18 08:33:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Verify if the list is already sorted
//return 1 for true, and 0 for false.
int	srt_verify_sorting(t_stack **stack)
{
	t_stack	*stack_current;

	stack_current = *stack;
	while (stack_current != NULL && stack_current->next != NULL)
	{
		if (stack_current->value > stack_current->next->value)
			return (0);
		else
			stack_current = stack_current->next;
	}
	return (1);
}

//Main function for sorting operations.
//Init stack_b
//delegate the right sorting algorithm depending of the nbr of nodes the list
void	srt_sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		qt_nodes_a;

	stack_b = NULL;
	qt_nodes_a = st_nodes_counter(stack_a);
	if (qt_nodes_a == 2)
		mov_sa(stack_a, 0);
	else if (qt_nodes_a == 3)
		srt_sort_three(stack_a);
	else if (qt_nodes_a > 3)
	{
		if (st_nodes_counter(stack_a) > 3)
			mov_pb(stack_a, &stack_b);
		if (st_nodes_counter(stack_a) > 3)
			mov_pb(stack_a, &stack_b);
		srt_turc_algorithm(stack_a, &stack_b);
	}
	st_list_free(stack_b);
}

//sort three numbers in ascending order 
//using the moviments specified by the exercise
void	srt_sort_three(t_stack **stack)
{
	if (st_findmax_value(stack) == (*stack)->value 
		&& st_findmin_value(stack) == (*stack)->next->next->value)
	{
		mov_sa(stack, 0);
		mov_rra(stack, 0); 
	}
	else if (st_findmax_value(stack) == (*stack)->next->value 
		&& st_findmin_value(stack) == (*stack)->value)
	{
		mov_sa(stack, 0);
		mov_ra(stack, 0);
	}
	else if (st_findmax_value(stack) == (*stack)->next->next->value)
		mov_sa(stack, 0);
	else if (st_findmin_value(stack) == (*stack)->next->next->value)
		mov_rra(stack, 0);
	else
		mov_ra (stack, 0);
}

//debug ./push_swap -34 56 -12 78 45 -89 23 67 -5 10
//Algorith to order stacks > 3
//More information of how the algorithm works on internet
void	srt_turc_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	st_update_b_values(stack_a, stack_b);
	stack_size = st_nodes_counter(stack_a);
	while (stack_size-- > 3 && !srt_verify_sorting(stack_a))
	{
		st_define_index(stack_b);
		st_update_a_values(stack_a, stack_b);
		srt_pb_less_qtmov(stack_a, stack_b);
	}
	st_update_b_values(stack_a, stack_b);
	st_putmax_ontop(stack_b);
	if (!srt_verify_sorting(stack_a))
		srt_sort_three(stack_a);
	if (!srt_verify_sorting(stack_a) && stack_size == 2)
		mov_sa(stack_a, 0);
	while ((*stack_b) != NULL)
	{
		st_define_index(stack_a);
		st_update_b_values(stack_a, stack_b);
		mov_put_ontop_a(stack_a, (*stack_b)->target);
		mov_pa(stack_a, stack_b);
	}
	st_define_index(stack_a);
	st_putmin_ontop(stack_a);
}

//move the node have less moviments to the top to stack_b.
//have in consideration if the node is above or below the med
//to move it together with the target or not.
//then, call mov_put_ontop_#() 
//to finish putting the node on top and push it to b.
void	srt_pb_less_qtmov(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*lessmoves_nd;

	if ((*stack_a) == NULL)
		return ;
	lessmoves_nd = srt_calc_lessmoves(stack_a);
	if (lessmoves_nd->above_med == 1 
		&& lessmoves_nd->target->above_med == 1)
		mov_rr_both(stack_a, stack_b, lessmoves_nd);
	else if (lessmoves_nd->above_med == 0 
		&& lessmoves_nd->target->above_med == 0)
		mov_rrr_both(stack_a, stack_b, lessmoves_nd);
	mov_put_ontop_a(stack_a, lessmoves_nd);
	mov_put_ontop_b(stack_b, lessmoves_nd->target);
	mov_pb(stack_a, stack_b);
}
