/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:15:10 by floblanc          #+#    #+#             */
/*   Updated: 2020/10/29 11:12:36 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include "../../libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memalloc(size_t size);

void	ft_memdel(void **ap);

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memdup(const void *s1, size_t n);

#endif
