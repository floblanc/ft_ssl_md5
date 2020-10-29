/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:15:45 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_list_push_front(t_list **begin_list, void *data, size_t len)
{
	t_list *tmp;

	if (*begin_list)
	{
		tmp = ft_lstnew(data, len);
		tmp->next = *begin_list;
		*begin_list = tmp;
	}
	else
		*begin_list = ft_lstnew(data, len);
}
