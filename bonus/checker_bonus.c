/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:20:06 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/23 08:22:49 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

//main of the checker
//define the argv, check if there is flags, see if the input is valid
//if is, initialize stack_a and stack_b, 
//get the input, compare the moviment with the input.
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
	if (validade_input_bonus(tmp, flags) == 1 && ft_isalpha(argv[1][0]) == 0)
	{
		stack_a = st_init_stack_a(tmp, flags);
		stack_b = NULL;
		input = get_next_line(0);
		cmp_input(&stack_a, &stack_b, input, flags);
		free_stacks(stack_a, stack_b);
	}
	else
		write(2, "Error\n", 6);
	free(flags);
	ft_free_all(tmp);
	return (0);
}

//Free 2 stacks at the same time
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

//free the strings after join then. Used to define argv
char	*ft_joinfree(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (tmp);
}

//free only one stack
void	free_one_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
