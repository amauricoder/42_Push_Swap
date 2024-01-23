/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:29:10 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/23 08:23:48 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

/******************************/
/*          Librarys          */
/******************************/
# include <unistd.h> //for read() / write()
# include <stdlib.h> //for malloc() / free() / exit()
# include <limits.h> // for INT_MAX ETC ETC
# include <strings.h> //for debug

/******************************/
/*          Sources           */
/******************************/
# include "../libft/libft.h"
# include "../push_swap.h"
# include "get_next_line_bonus.h"
/******************************/
/*           Structs          */
/******************************/
typedef struct s_flags
{
	int	disp_c;
	int	disp_s;
}		t_flags;

/******************************/
/*         BONUS MAIN         */
/*      checker_bonus.c       */
/******************************/
int			main(int argc, char **argv);
void		free_stacks(t_stack *stack_a, t_stack *stack_b);
void		error_message(void);
char		*ft_joinfree(char *s1, char *s2);
void		free_one_stack(t_stack *stack);
/******************************/
/*        Val BONUS           */
/*    ft_val_utils_bonus.c    */
/******************************/
int			validade_input_bonus(char **argv, t_flags *flags);
t_flags		*validade_check_flag(char **argv);
int			validade_format_bonus(char **argv);
void		validade_movs(char *input, t_stack **stack_a, t_stack **stack_b);
void		valid_movs_color(char *input, t_stack **stack_a, t_stack **stack_b);
/******************************/
/*          MOV_BONUS         */
/*         mov_bonus.c        */
/******************************/
void		mov_ss_bonus(t_stack **stack_a, t_stack **stack_b);
void		mov_rr_bonus(t_stack **stack_a, t_stack **stack_b, int flag);
void		mov_rrr_bonus(t_stack **stack_a, t_stack **stack_b, int flag);
void		mov_pa_bonus(t_stack **stack_a, t_stack **stack_b);
void		mov_pb_bonus(t_stack **stack_a, t_stack **stack_b, int flag);
/******************************/
/*        BONUS UTILS         */
/*      ft_utils_bonus.c      */
/******************************/
void		st_printstack_color(t_stack *stack, char stack_letter);
char		**st_define_argv(char **argv);
void		*st_init_stack_a(char **argv, t_flags *flags);
void		check_flag(t_stack **sa, t_stack **sb, char *input, t_flags *flags);
void		cmp_input(t_stack **sa, t_stack **sb, char *input, t_flags *flags);
#endif