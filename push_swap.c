/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:29:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/05 23:07:30 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	if (validade_input(argv) == 1)
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
