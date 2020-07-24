/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:08:59 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:36:13 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
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
			while (haystack[i] == needle[j]
					&& haystack[i] != '\0' && needle[j] != '\0')
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
