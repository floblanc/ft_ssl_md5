/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:14:49 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t	i;

	i = ft_strlen(s1);
	while (*s2)
		s1[i++] = *(s2++);
	s1[i] = '\0';
	return (s1);
}
