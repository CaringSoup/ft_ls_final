/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 09:58:44 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:09:39 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	conv_ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 97);
	else
		return (nb + 48);
}

char		*itoa_base(int num, int base)
{
	int		i;
	char	*str;
	int		tmp;

	i = 0;
	tmp = num;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i + 1] = 0;
	while (i >= 0)
	{
		tmp = num % base;
		str[i] = conv_ex(tmp);
		num /= base;
		i--;
	}
	return (str);
}
