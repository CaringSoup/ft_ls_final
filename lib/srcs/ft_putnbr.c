/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:50:14 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:50:32 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(long long int nb)
{
	if (nb == LONG_MIN)
		ft_putstr("-9223372036854775808");
	if (nb < 0 && nb != LONG_MIN)
	{
		ft_putchar(45);
		nb = -nb;
	}
	if (nb >= 10 && nb != LONG_MIN)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb != LONG_MIN)
	{
		ft_putchar(nb + 48);
	}
}

