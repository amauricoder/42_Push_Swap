/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:45:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/15 16:44:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//(rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.
void	mov_ra(t_stack **stack_a, int flag)
{
	t_stack	*first_node;
	t_stack	*current;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first_node = *stack_a; //primeiro node
	current = first_node->next;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack_a; // ultimo
	
	*stack_a = first_node->next; // o primeiro vira o segundk
	
	first_node->next = NULL;
	if (flag == 0)
		ft_printf("ra\n");
}

//(rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.
void	mov_rb(t_stack **stack_b, int flag)
{
	t_stack	*first_node;
	t_stack	*current;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first_node = *stack_b; 
	current = first_node->next;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack_b;
	*stack_b = first_node->next;
	first_node->next = NULL;
	if (flag == 0)
		ft_printf("rb\n");
}

//mov_ra and mov_rb at the same time.
void	mov_rr(t_stack **stack_a, t_stack **stack_b)
{
	mov_ra(stack_a, 1);
	mov_rb(stack_b, 1);
	ft_printf("rr\n");
}

//put a specific node and the target on top of stack using mov_rr.
void	mov_rr_both(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	while (*stack_b != node->target && *stack_a != node)
		mov_rr(stack_a, stack_b);
	st_define_index(stack_a);
	st_define_index(stack_b);
}