/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:20:06 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/21 20:59:48 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker_bonus.h"

int	main(int argc, char **argv)
{
	char	*input;
	t_flags *flags;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	
	argv = st_define_argv(argc, argv);
	flags = validade_check_flag(argv);
	if (validade_input_bonus(argv) == 1)
	{
		input = get_next_line(0);
		stack_a = st_init_stack_a(argv, flags);
		stack_b = NULL;
		compare_input(&stack_a, &stack_b, input, flags);
		free_stacks(stack_a, stack_b);
		free(input);
	}
	else
		write(2, "Error\n", 6);
	free(flags);
	if (argc == 2)
		ft_free_all(argv);
	return (0);
}
void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free (stack_a);
	free (stack_b);
}

void	error_message(void)
{
	write(2, "Error\n", 7);
	exit (0);
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
