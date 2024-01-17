/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:44:55 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/17 08:30:42 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//mov_sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	mov_sa(t_stack **stack_a, int flag)
{
	t_stack	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (flag == 0)
		ft_printf("sa\n");
	return ;
}

//mov_sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
void	mov_sb(t_stack **stack_b, int flag)
{
	t_stack	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (flag == 0)
		ft_printf("sb\n");
	return ;
}

//mov_ss : mov_sa and mov_sb at the same time.
void	mov_ss(t_stack **stack_a, t_stack **stack_b)
{
	mov_sa(stack_a, 1);
	mov_sb(stack_b, 1);
	ft_printf("ss\n");
	return ;
}
