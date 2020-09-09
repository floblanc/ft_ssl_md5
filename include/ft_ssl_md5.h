/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:26:51 by floblanc          #+#    #+#             */
/*   Updated: 2020/09/09 14:40:56 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5
# define FT_SSL_MD5

# include "../libftprintf/include/libprintf.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct      s_var
{
    unsigned int    h0;
    unsigned int    h1;
    unsigned int    h2;
    unsigned int    h3;
    unsigned int    a;
    unsigned int    b;
    unsigned int    c;
    unsigned int    d;
    unsigned int    f;
    unsigned int    g;
    unsigned int    r[64];
    unsigned int    k[64];
    size_t          len;
}                   t_var;

#endif