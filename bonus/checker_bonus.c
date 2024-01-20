/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:29:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/20 19:29:59 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	char	*input;
	t_flags *flags;
	
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	validade_check_flag(argv, flags);
	input = get_next_line(0);
	
	if (validade_input_bonus(argv) == 1)
	{
		ft_printf("entrou no if \n");
		while (input != NULL)
		{
				ft_printf("WORKED => %s", input);
				free(input);
				input = get_next_line(0);
		}
	}
	
	ft_printf("COLOR %i \n", flags->disp_c);
	ft_printf("STACK %i \n", flags->disp_s);
	free(input);
	free(flags);
}

int	push_swap_bonus(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
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
		ft_printf("Error\n");
	if (argc == 2)
		ft_free_all(argv);
	return (0);
}
