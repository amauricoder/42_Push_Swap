/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:54:54 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/31 12:58:57 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

//st_printstack() prints all the values of the nodes in the list
void	st_printstack_color(t_stack *stack, char stack_letter)
{
	if (stack_letter == 'a')
		ft_printf(GREEN "╔═══════════════════╗\n" "║      STACK A      ║\n"
			"╠═══════════════════╣\n"RESET);
	else if (stack_letter == 'b')
		ft_printf(MGT "╔═══════════════════╗\n" "║       STACK B     ║\n"
			"╠═══════════════════╣\n"RESET);
	if (stack != NULL)
	{
		while (stack != NULL)
		{
			ft_printf("  Value    =   %i   \n", stack->value);
			stack = stack->next;
		}
		if (stack_letter == 'a')
			ft_printf(GREEN "╚═══════════════════╝\n" RESET);
		else
			ft_printf(MGT "╚═══════════════════╝\n" RESET);
	}
	else
	{
		if (stack_letter == 'a')
			ft_printf(GREEN"║       EMPTY       ║\n╚═══════════════════╝\n"RESET);
		else
			ft_printf(MGT"║       EMPTY       ║\n╚═══════════════════╝\n"RESET);
	}
}

char	**st_define_argv(char **argv)
{
	char	*buffer;
	char	**tmp;
	int		i;

	i = 0;
	buffer = ft_strdup("");
	while (argv[++i])
	{
		buffer = ft_joinfree(buffer, ft_strdup(argv[i]));
		buffer = ft_joinfree(buffer, ft_strdup(" "));
	}
	tmp = ft_split(buffer, ' ');
	free(buffer);
	return (tmp);
}

void	*st_init_stack_a(char **argv, t_flags *flags)
{
	t_stack	*stack_a;

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

void	check_flag(t_stack **sa, t_stack **sb, char *input, t_flags *flags)
{
	if (flags->disp_c)
		valid_movs_color(input, sa, sb);
	else
		validade_movs(input, sa, sb);
	if (flags->disp_s)
	{
		st_printstack_color((*sa), 'a');
		st_printstack_color((*sb), 'b');
	}
}

void	cmp_input(t_stack **sa, t_stack **sb, char *input, t_flags *flags)
{
	while (1)
	{
		if (input == NULL || input[0] == '\0')
			break ;
		check_flag(sa, sb, input, flags);
		free(input);
		input = get_next_line(0);
	}
	if ((*sb) == NULL)
	{
		if (srt_verify_sorting(sa) == 1)
			ft_printf("OK\n");
		else
			write(2, "KO\n", 3);
	}
	else
		write(2, "KO\n", 3);
}
