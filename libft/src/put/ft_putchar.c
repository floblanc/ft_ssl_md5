/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:13:20 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

void	ft_putchar(int c)
{
	size_t	len;
	char	*a;

	len = ft_unicode_len(c);
	if (len > 1)
	{
		if (!(a = (char*)ft_memalloc(sizeof(char) * (len + 1))))
			return ;
		a = ft_unicode(a, c);
		write(1, a, len);
	}
	else
		write(1, &c, 1);
}
