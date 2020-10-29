/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:13:27 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

void	ft_putchar_fd(int c, int fd)
{
	size_t	len;
	char	*a;

	len = ft_unicode_len(c);
	if (len > 1)
	{
		if (!(a = (char*)ft_memalloc(sizeof(char) * (len + 1))))
			return ;
		a = ft_unicode(a, c);
		write(fd, a, len);
	}
	else
		write(fd, &c, 1);
}
