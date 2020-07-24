/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:56:42 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:28:34 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)malloc(size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return ((void *)str);
}
