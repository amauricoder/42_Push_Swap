/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:53:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/16 20:32:01 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//(reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	mov_rra(t_stack **stack_a, int flag)
{
	t_stack *current;
	t_stack *new_last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
    {
        return;
    }
    
    
	current = *stack_a;
   	new_last = NULL;
    while (current->next != NULL)
    {
        new_last = current;
        current = current->next;
    }
    new_last->next = NULL;
    current->next = *stack_a;
    *stack_a = current;
    if (flag == 0)
        ft_printf("rra\n");
}

//(reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
void mov_rrb(t_stack **stack_b, int flag)
{
	t_stack *current;
	t_stack *new_last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
    {
        return;
    }
    
	current = *stack_b;
   	new_last = NULL;
    while (current->next != NULL)
    {
        new_last = current;
        current = current->next;
    }
    new_last->next = NULL;
    current->next = *stack_b;
    *stack_b = current;
    if (flag == 0)
        ft_printf("rrb\n");
}

//mov_rra and mov_rrb at the same time.
void	mov_rrr(t_stack **stack_a, t_stack **stack_b)
{
	mov_rra(stack_a, 1);
	mov_rrb(stack_b, 1);
	ft_printf("rrr\n");
}
//put a specific node and the target on top of stack using mov_rrr.
void	mov_rrr_both(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	while (*stack_a != node && *stack_b != node->target)
		mov_rrr(stack_a, stack_b);
	st_define_index(stack_a);
	st_define_index(stack_b);
}