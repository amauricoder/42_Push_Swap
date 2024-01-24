/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:50:02 by aconceic          #+#    #+#             */
/*   Updated: 2024/01/23 17:05:44 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//****************************************************************************//
//                                 Libraries                                  //
//****************************************************************************//
# include <stdlib.h> // for mallocs
# include <unistd.h> //for read()
# include <stdio.h> //necessary for FOPEN_MAX
//# include <fcntl.h> //necessary for tests open() flags, exclude to push

//****************************************************************************//
//                                 Functions                                  //
//****************************************************************************//
char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(char *s);
void	*ft_calloc_gnl(size_t nmemb, size_t size);

#endif