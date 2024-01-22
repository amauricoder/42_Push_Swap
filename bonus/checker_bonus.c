/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:20:06 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/22 11:26:27 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	char	*input;
	char	**tmp;
	t_flags	*flags;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	tmp = st_define_argv(argv);
	flags = validade_check_flag(tmp);
	if (validade_input_bonus(tmp, flags) == 1)
	{
		input = get_next_line(0);
		stack_a = st_init_stack_a(tmp, flags);
		stack_b = NULL;
		cmp_input(&stack_a, &stack_b, input, flags);
		free_stacks(stack_a, stack_b);
	}
	else
		write(2, "Error\n", 6);
	free(flags);
	ft_free_all(tmp);
	return (0);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
	while (stack_b)
	{
		tmp = stack_b->next;
		free(stack_b);
		stack_b = tmp;
	}
}

char	*ft_joinfree(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (tmp);
}
/* 
int	push_swap_bonus(int argc, char **argv)
{
	t_stack	*stack_a;

	
	if (validade_input_bonus(argv) == 1)
	{
		stack_a = st_init_stack(argv);
		if (srt_verify_sorting(&stack_a) == 0)
		{
			srt_sort_stack(&stack_a);
			st_list_free(stack_a);
		}
		else
			st_list_free(stack_a);
	}
	else
		write(2, "Error\n", 7);
	
	return (0);
} */
