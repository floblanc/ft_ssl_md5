/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:34:24 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strnbstr(const char *s1, const char *s)
{
	size_t	i;
	size_t	len;
	size_t	nb;

	i = 0;
	nb = 0;
	if (!*s)
		return (0);
	len = ft_strlen(s);
	while (s1[i])
	{
		if (s1[i] == *s)
			if (ft_strncmp(&s1[i], s, len) == 0)
				nb++;
		i++;
	}
	return (nb);
}
