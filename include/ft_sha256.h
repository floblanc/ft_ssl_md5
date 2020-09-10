/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:49:28 by apouchet          #+#    #+#             */
/*   Updated: 2020/09/10 14:09:005 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <math.h>
# include <fcntl.h>
# include "../libftprintf/include/libprintf.h"


# define STDIN 0
# define STDOUT 1
# define STDERR 2
typedef struct	s_var
{
	unsigned int	h0;
	unsigned int	h1;
	unsigned int	h2;
	unsigned int	h3;
	unsigned int	h4;
	unsigned int	h5;
	unsigned int	h6;
	unsigned int	h7;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	k[64];
	unsigned int	w[64];
	size_t			len;
}					t_var;
#endif