/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:55:15 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/21 18:26:10 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	mov_ss_bonus(t_stack **stack_a, t_stack **stack_b)
{
	mov_sa(stack_a, 1);
	mov_sb(stack_b, 1);
	ft_printf(RED"ss\n"RESET);
	return ;
}

void	mov_rr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	mov_ra(stack_a, 1);
	mov_rb(stack_b, 1);
	ft_printf(RED"rr\n"RESET);
}

void	mov_rrr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	mov_rra(stack_a, 1);
	mov_rrb(stack_b, 1);
	ft_printf(RED"rrr\n"RESET);
}

void	mov_pa_bonus(t_stack **stack_a, t_stack **stack_b)
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
	ft_printf(RED"pa\n"RESET);
}

void	mov_pb_bonus(t_stack **stack_a, t_stack **stack_b)
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
	ft_printf(RED"pb\n"RESET);
}
