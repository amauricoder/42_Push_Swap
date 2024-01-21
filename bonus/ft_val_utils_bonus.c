/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:36:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/21 21:01:53 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
//general validation function. Contains three other validations inside.
//return 1 if every validation pass.
int	validade_input_bonus(char **argv)
{
	if ((!(validade_format_bonus(argv)) || !(validade_duplication(argv)) 
			|| !(validade_nbrlimits(argv))))
		return (0);
	return (1);
}

t_flags	*validade_check_flag(char **argv)
{
	int	i;
	t_flags *flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	i = 0;
	flags->disp_c = 0;
	flags->disp_s = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'c')
				flags->disp_c = 1;
			else if (argv[i][1] == 's')
				flags->disp_s = 1;
		}
		i ++;
	}
	return (flags);
}

//Guarantee that the digits are on a valid input.
//Return 1 for valid input and 0 instead.
int	validade_format_bonus(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i] != (void *)0)
	{
		if (ft_strcmp(argv[i], "-c") == 0 || ft_strcmp(argv[i], "-s") == 0)
			continue ;
		j = 0;
		if (argv[i][0] == '\0')
			return (0);
		if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
			return (0);
		j ++;
		while (argv[i][j] != '\0')
		{
			if (!(ft_isdigit(argv[i][j])))
				return (0);
			j ++;
		}
	}
	return (1);
}

void	validade_movs(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(input, "sa\n") == 0)
		mov_sa(stack_a, 1);
	else if (ft_strcmp(input, "sb\n") == 0)
		mov_sb(stack_b, 1);
	else if (ft_strcmp(input, "ss\n") == 0)
		mov_ss(stack_a, stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		mov_ra(stack_a, 1);
	else if (ft_strcmp(input, "rb\n") == 0)
		mov_rb(stack_b, 1);
	else if (ft_strcmp(input, "rr\n") == 0)
		mov_rr(stack_a, stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		mov_rra(stack_a, 1);
	else if (ft_strcmp(input, "rrb\n") == 0)
		mov_rrb(stack_b, 1);
	else if (ft_strcmp(input, "rrr\n") == 0)
		mov_rrr(stack_a, stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		mov_pa(stack_a, stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		mov_pb(stack_a, stack_b);
	else
		error_message();
}

void	valid_movs_color(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(input, "sa\n") == 0)
		mov_sa(stack_a, 2);
	else if (ft_strcmp(input, "sb\n") == 0)
		mov_sb(stack_b, 2);
	else if (ft_strcmp(input, "ss\n") == 0)
		mov_ss_bonus(stack_a, stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		mov_ra(stack_a, 2);
	else if (ft_strcmp(input, "rb\n") == 0)
		mov_rb(stack_b, 2);
	else if (ft_strcmp(input, "rr\n") == 0)
		mov_rr_bonus(stack_a, stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		mov_rra(stack_a, 2);
	else if (ft_strcmp(input, "rrb\n") == 0)
		mov_rrb(stack_b, 2);
	else if (ft_strcmp(input, "rrr\n") == 0)
		mov_rrr_bonus(stack_a, stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		mov_pa_bonus(stack_a, stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		mov_pb_bonus(stack_a, stack_b);
	else
		error_message();
}
//main for functions testing purposes
//comment push_swap.h before testing this functions, to prevent incompatibility.
//and compile just this file, without make.
/* #include <stdio.h>
int main(void)
{
	//test validade_format
	char *test1[] = {"42", "43", "44", NULL};
	char *test2[] = {"42", "4215153", "-44", NULL};
	char *test3[] = {"abc", "def", "-44", NULL};
	
	ft_printf("1 ===> %i\n", validade_format(test1));
	ft_printf("1 ===> %i\n", validade_format(test2));
	ft_printf("0 ===> %i\n", validade_format(test3));
}  */

/* //TEST VALIDADE_DUPLICATION
#include <stdio.h>
int	main(void)
{
	char *test1[] = {"42", "42", "44", NULL};
	char *test2[] = {"42", "43", "44", NULL};
	char *test3[] = {"-42", "43", "-42", NULL};
	char *test4[] = {"-42", "-60", "-88", NULL};
	
	ft_printf("0 ===> %i\n", validade_duplication(test1));
	ft_printf("1 ===> %i\n", validade_duplication(test2));
	ft_printf("0 ===> %i\n", validade_duplication(test3));
	ft_printf("1 ===> %i\n", validade_duplication(test4));
} */
