/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:15:59 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strlen_find(const char *s, int c)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
	{
		if (s[len] == (char)c)
			return (len);
		len++;
	}
	return (0);
}
