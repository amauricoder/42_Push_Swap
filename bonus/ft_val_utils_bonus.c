/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:36:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/20 20:07:39 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
//general validation function. Contains three other validations inside.
//return 1 if every validation pass.
int	validade_input_bonus(char **argv)
{
 	if ((!(validade_format_bonus(argv)) || !(validade_duplication(argv)) 
		|| !(validade_nbrlimits(argv))))
		return (0);
/* 	ft_printf(" => %i\n ", validade_format_bonus(argv));
	ft_printf(" => %i\n ", validade_duplication(argv));
	ft_printf(" => %i\n ", validade_nbrlimits(argv)); */
	return (1);
}

void validade_check_flag(char **argv, t_flags *flags)
{
	int i;
	
	i = 0;
	flags->disp_c = 0;
	flags->disp_s = 0;
	while(argv[i])
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'c')
				flags->disp_c = 1;
			else if (argv[i][1] == 'v')
				flags->disp_s = 1;
		}
		i ++;
	}
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
			continue;
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
