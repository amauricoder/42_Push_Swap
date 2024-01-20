/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:29:10 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/20 20:08:49 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

/******************************/
/*    COLORS ANSI ESCAPE      */
/******************************/
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

/******************************/
/*          Librarys          */
/******************************/
# include <unistd.h> //for read() / write()
# include <stdlib.h> //for malloc() / free() / exit()
# include <limits.h> // for INT_MAX ETC ETC

/******************************/
/*          Sources           */
/******************************/
# include "../libft/libft.h"
# include "../push_swap.h"
# include "get_next_line_bonus.h"
/******************************/
/*           Structs          */
/******************************/
typedef	struct s_flags
{
	int disp_c;
	int	disp_s;
}	t_flags;

/******************************/
/*          push_swap.c       */
/******************************/
int			main(int argc, char **argv); 
int			push_swap_bonus(int argc, char **argv);
/******************************/
/*        Validations         */
/*     ft_val_functions.c     */
/******************************/
int			validade_input_bonus(char **argv);
void 		validade_check_flag(char **argv, t_flags *flags);
int			validade_format_bonus(char **argv);

#endif