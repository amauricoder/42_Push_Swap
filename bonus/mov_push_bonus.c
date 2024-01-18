/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:45:03 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/18 14:13:59 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

//mov_pa (push a): Take the first element at the top of b 
//and put it at the top of a.
//Do nothing if b is empty.
//This function define also the index and if it is above_med
void	mov_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b_first_element;
	t_stack	*a_first_element;

	if (*stack_b == NULL)
		return ;
	a_first_element = *stack_a;
	b_first_element = *stack_b;
	*stack_b = b_first_element->next;
	b_first_element->next = a_first_element;
	*stack_a = b_first_element;
	ft_printf("pa\n");
}

//mov_pb (push b): Take the first element at the top of a 
//and put it at the top of b.
//Do nothing if a is empty.
//This function define also the index and if it is above_med
void	mov_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_first_element;
	t_stack	*b_first_element;

	if (*stack_a == NULL)
		return ;
	a_first_element = *stack_a;
	b_first_element = *stack_b;
	*stack_a = a_first_element->next;
	a_first_element->next = b_first_element;
	*stack_b = a_first_element;
	ft_printf("pb\n");
}

// put a specific node on top on stack_a
//have in consideration if its above med or not.
void	mov_put_ontop_a(t_stack **stack_a, t_stack *node)
{
	while ((*stack_a)->value != node->value)
	{
		if (node->above_med == 1)
			mov_ra(stack_a, 0);
		else
			mov_rra(stack_a, 0);
	}
}

// put a specific node on top on stack_b
//have in consideration if its above med or not.
void	mov_put_ontop_b(t_stack **stack_b, t_stack *node)
{
	while (*stack_b != node)
	{
		if (node->above_med == 1)
			mov_rb(stack_b, 0);
		else
			mov_rrb(stack_b, 0);
	}
}
