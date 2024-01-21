/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:54:54 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/21 20:46:46 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

//st_printstack() prints all the values of the nodes in the list
void	st_printstack_color(t_stack *stack, char stack_letter)
{
	if (stack_letter == 'a')
		ft_printf(GREEN "STACK A \n" RESET);
	else if (stack_letter == 'b')
		ft_printf(MAGENTA "STACK B \n" RESET);
	if (stack != NULL)
	{
		while (stack != NULL)
		{
			ft_printf("=> %i \n", stack->value);
			stack = stack->next;
		}
	}
	else
		ft_printf("EMPTY \n");
	ft_printf("\n");
}
char	**st_define_argv(int argc, char **argv)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	return (argv);
}
void	*st_init_stack_a(char **argv, t_flags *flags)
{
	t_stack *stack_a;

	if (flags->disp_c && flags->disp_s)
		stack_a = st_init_stack(argv + 2);
	else if (flags->disp_c)
		stack_a = st_init_stack(argv + 1);
	else if (flags->disp_s)	
		stack_a = st_init_stack(argv + 1);
	else
		stack_a = st_init_stack(argv);
	return (stack_a);
}

void	validade_operations(t_stack **stack_a, t_stack **stack_b, char *input, t_flags *flags)
{
	if (flags->disp_c)
		valid_movs_color(input, stack_a, stack_b);
	else
		validade_movs(input, stack_a, stack_b);
	if (flags->disp_s)
	{
		st_printstack_color((*stack_a), 'a');
		st_printstack_color((*stack_b), 'b');
	}
}
void	compare_input(t_stack **stack_a, t_stack **stack_b, char *input, t_flags *flags)
{
	while (1)
		{
			if (input == NULL || input[0] == '\0')
        		break;
			validade_operations(stack_a, stack_b, input, flags);
			input = get_next_line(0);
		}
		if ((*stack_b) == NULL)
		{
			if (srt_verify_sorting(stack_a) == 1)
				ft_printf("OK\n");
			else
				write(2, "KO\n", 3);
		}
		else
			write(2, "KO\n", 3);
			
}
