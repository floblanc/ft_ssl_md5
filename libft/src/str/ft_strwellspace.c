/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwellspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:17:23 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strwellspace(const char *s)
{
	char	*a;
	char	*b;
	int		i;
	int		len;

	if (!s || !(a = ft_strtrim(s)))
		return (NULL);
	if (!(b = (char*)ft_memalloc(sizeof(char) *
					(ft_nbalpha(s) + ft_count_word(a)))))
		return (NULL);
	i = 0;
	len = 0;
	while (a[i])
	{
		while (a[i] && !ft_isspace(a[i]))
			b[len++] = a[i++];
		if (a[i] && !ft_isspace(a[i - 1]))
			b[len++] = ' ';
		if (a[i])
			i++;
	}
	free(a);
	return (b);
}
