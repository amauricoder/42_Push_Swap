/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:17:51 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/18 14:13:24 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
//ft_strcmp() compares the values of 2 strs
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]))
		i ++;
	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
}

//free all itens in a double pointers of arrays
int	ft_free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

//the same as atoi(), but accept long number.
long long	ft_atol(const char *nptr)
{
	long long	signal;
	long long	number;

	signal = 1;
	number = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr ++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		number *= 10;
		number += *nptr - 48;
		nptr ++;
	}
	number *= signal;
	return (number);
}

//Return the absolute value of a number.
int	ft_abs(int value)
{
	if (value < 0)
		return (value * -1);
	else
		return (value);
}
