/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:11:49 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	size_t				i;

	a = (unsigned char*)d;
	b = (const unsigned char*)s;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (a[i++] == (unsigned char)c)
			return (&a[i]);
	}
	return (NULL);
}
