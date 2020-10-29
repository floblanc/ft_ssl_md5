/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:14:02 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

# include "../../libft.h"

void	ft_putchar(int c);

void	ft_putchar_fd(int c, int fd);

void	ft_putstr(char const *s);

void	ft_putstr_fd(char const *s, int fd);

void	ft_putendl_fd(char const *s, int fd);

void	ft_putendl(char const *s);

void	ft_putnbr(int n);

void	ft_putnbr_fd(int n, int fd);

#endif
