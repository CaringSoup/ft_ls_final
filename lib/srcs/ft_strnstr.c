/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:14:43 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:35:42 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j] && haystack[i] != '\0'
					&& needle[j] != '\0' && i < len)
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
			i = (i - j);
		}
		i++;
	}
	return (NULL);
}
