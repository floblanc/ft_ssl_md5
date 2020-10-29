/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:15:26 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strdup_free(char **s1)
{
	char *a;

	if (!(a = (char*)ft_memalloc(sizeof(char) * (ft_strlen(*s1) + 1))))
		return (NULL);
	a = ft_strcpy(a, *s1);
	ft_strdel(s1);
	return (a);
}
