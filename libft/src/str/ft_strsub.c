/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:06:46 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strsub(char const *s, size_t start, size_t len)
{
	size_t	i;
	char	*a;

	if (!s || start + len > ft_strlen(s) || !(a = (char*)ft_memalloc(len + 1)))
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		a[i++] = s[start++];
	return (a);
}
