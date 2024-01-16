/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:29:10 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/16 19:43:03 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/******************************/
/*          Librarys          */
/******************************/
# include <unistd.h> //for read() / write()
# include <stdlib.h> //for malloc() / free() / exit()
# include <limits.h> // for INT_MAX ETC ETC

/******************************/
/*          Sources           */
/******************************/
# include "libft/libft.h"
/******************************/
/*           Structs          */
/******************************/
typedef struct s_stack
{
	int				value;
	int				index;
	int				qt_mov_top;
	int				above_med;

	struct s_stack	*next;
	struct s_stack	*target;

}					t_stack;

/******************************/
/*          push_swap.c       */
/******************************/
//int				main(void); 
int			main(int argc, char **argv);
/******************************/
/*        Validations         */
/*     ft_val_functions.c     */
/******************************/
int			validade_input(char **argv);
int			validade_format(char **argv);
int			validade_nbrlimits(char **number);
int			validade_duplication(char **number);
/******************************/
/*       General utils        */
/*     ft_general_utils.c     */
/******************************/
int			ft_strcmp(char *s1, char *s2);
int			ft_free_all(char **str);
long long	ft_atol(const char *nptr);
int			ft_abs(int value);
/******************************/
/*           Stack            */
/*      st_stack_utils.c      */
/******************************/
t_stack		*st_init_stack(char **argv);
t_stack		*st_findbigger_node(t_stack **stack);
t_stack		*st_findlower_node(t_stack **stack);
void		st_printstack(t_stack *stack);
int			st_nodes_counter(t_stack **stack);
/******************************/
/*           Stack            */
/*   st_stack_definition.c    */
/******************************/
void		st_define_index(t_stack **stack);
void		st_define_lower_target(t_stack **stack_a, t_stack **stack_b);
void		st_update_b_values(t_stack **stack_a, t_stack **stack_b);
void		st_define_bigger_target(t_stack **stack_a, t_stack **stack_b);
void		st_update_a_values(t_stack **stack_a, t_stack **stack_b);
/******************************/
/*            List            */
/*       st_list_utils.c      */
/******************************/
t_stack		*st_newitem(int value);
void		st_item_addback(t_stack **lst, t_stack *new);
void		st_list_free(t_stack *head);
void		st_putmax_ontop(t_stack **stack);
void		st_putmin_ontop(t_stack **stack);
/******************************/
/*       Moviments Swap       */
/*          mov_swap.c        */
/******************************/
void		mov_sa(t_stack **stack_a, int flag);
void		mov_sb(t_stack **stack_b, int flag);
void		mov_ss(t_stack **stack_a, t_stack **stack_b);
/******************************/
/*       Moviments Rotate     */
/*          mov_rotate.c      */
/******************************/
void		mov_ra(t_stack **stack_a, int flag);
void		mov_rb(t_stack **stack_b, int flag);
void		mov_rr(t_stack **stack_a, t_stack **stack_b);
void		mov_rr_both(t_stack **stack_a, t_stack **stack_b, t_stack *node);
/******************************/
/*  Moviments Reverse Rotate  */
/*      mov_revrotate.c       */
/******************************/
void		mov_rra(t_stack **stack_a, int flag);
void		mov_rrb(t_stack **stack_b, int flag);
void		mov_rrr(t_stack **stack_a, t_stack **stack_b);
void		mov_rrr_both(t_stack **stack_a, t_stack **stack_b, t_stack *node);
/******************************/
/*  Mov Push & Put nd on top  */
/*          mov_push.c        */
/******************************/
void		mov_pa(t_stack **stack_a, t_stack **stack_b);
void		mov_pb(t_stack **stack_a, t_stack **stack_b);
void		mov_put_ontop_a(t_stack **stack_a, t_stack *node);
void		mov_put_ontop_b(t_stack **stack_b, t_stack *node);
/******************************/
/*     Sorting Operations     */
/*  srt_sorting_operations.c  */
/******************************/
int			srt_verify_sorting(t_stack **stack);
void		srt_sort_stack(t_stack **stack);
void		srt_sort_three(t_stack **stack);
void		srt_turc_algorithm(t_stack **stack_a, t_stack **stack_b);
void		srt_pb_less_qtmov(t_stack **stack_a, t_stack **stack_b);
void		st_null_all_targets(t_stack **stack_a, t_stack **stack_b);
/******************************/
/*     Sorting Calculation    */
/* srt_sorting_calculation.c  */
/******************************/
t_stack		*srt_calc_lessmoves(t_stack **stack_a);
void		st_calculate_qtmov(t_stack **stack_a, t_stack **stack_b);
int			st_findmax_value(t_stack **stack);
int			st_findmin_value(t_stack **stack);
#endif