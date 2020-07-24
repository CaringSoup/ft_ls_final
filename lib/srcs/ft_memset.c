/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:43:28 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:41:06 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*j;

	i = 0;
	j = (unsigned char *)b;
	while ((size_t)i < len)
	{
		j[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
