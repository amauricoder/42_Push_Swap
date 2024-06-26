/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:36:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/23 09:38:07 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//general validation function. Contains three other validations inside.
//return 1 if every validation pass.
int	validade_input(char **argv)
{
	if (!(validade_format(argv)) || !(validade_duplication(argv)) 
		|| !(validade_nbrlimits(argv)))
		return (0);
	return (1);
}

//Validade int limits. Return 1 for a number that is valid, and 0 instead.
int	validade_nbrlimits(char **number)
{
	int	i;

	i = 0;
	while (number[i] != NULL)
	{
		if (ft_atol(number[i]) > 2147483647 
			|| ft_atol(number[i]) < -2147483648)
			return (0);
		i ++;
	}
	return (1);
}

//Validade duplicate numbers. Return 1 if there is no dupli, and 0 instead.
int	validade_duplication(char **number)
{
	int	i;
	int	j;
	int	*numeric_values;
	int	numeric_value;

	i = -1;
	j = 0;
	numeric_values = (int *)malloc(sizeof(int) * ft_argument_counter(number));
	while (number[++i] != (void *)0)
	{
		numeric_value = atoi(number[i]);
		numeric_values[i] = numeric_value;
		j = 0;
		while (j < i)
		{
			if (numeric_values[j] == numeric_value)
			{
				free(numeric_values);
				return (0);
			}
			j++;
		}
	}
	free(numeric_values);
	return (1);
}

//Guarantee that the digits are on a valid input.
//Return 1 for valid input and 0 instead.
int	validade_format(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] != (void *)0)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (0);
		if (!(ft_isdigit(argv[i][j]) 
			|| (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))))
			return (0);
		j ++;
		while (argv[i][j] != '\0')
		{
			if (!(ft_isdigit(argv[i][j])))
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit (0);
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
