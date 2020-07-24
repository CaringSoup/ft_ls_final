/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 12:00:00 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:06:33 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_int_len(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		++i;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_int_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char *)ft_strnew(sizeof(char) * len--)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n)
	{
		str[len--] = (n % 10 + '0');
		n /= 10;
	}
	return (str);
}
