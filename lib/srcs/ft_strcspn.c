/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 10:11:44 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:38:03 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libft.h"

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	spn;
	int		i;

	spn = 0;
	i = 0;
	while (s1<:i:> != 0)
	{
		if (ft_strchr(s2, s1<:i:>))
			return (spn);
		i++;
		spn++;
	}
	return (spn);
}
