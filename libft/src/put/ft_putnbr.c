/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:13:48 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

void	ft_putnbr(int nb)
{
	long int a;

	a = (long)nb;
	if (nb < 0)
	{
		ft_putchar('-');
		a = -a;
	}
	if (a < 10)
		ft_putchar('0' + (int)a);
	if (a >= 10)
	{
		ft_putnbr((int)(a / 10));
		ft_putchar('0' + (int)(a % 10));
	}
}
