/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:15:02 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_H
# define IS_H

# include "../../libft.h"

int		ft_isalpha(int c);

int		ft_isspace(char c);

int		ft_isprint(int c);

int		ft_isalnum(int	c);

int		ft_isdigit(int	c);

int		ft_isascii(int	c);

int		ft_islower(int	c);

int		ft_isupper(int	c);

int		ft_ischar(const char *s, char c);

#endif
