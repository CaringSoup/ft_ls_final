/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:51:40 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:41:21 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*dest;
	const char	*source;

	i = (int)len - 1;
	dest = (char *)dst;
	source = (const char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (i >= 0)
		{
			dest[i] = source[i];
			i--;
		}
	}
	return ((void *)dst);
}
