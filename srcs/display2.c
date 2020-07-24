/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:32:56 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/24 13:32:45 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	output(char *str, int xsze)
{
	int		num;

	num = xsze - ft_strlen(str);
	ft_putstr(str);
	while (num-- > 0)
		ft_putchar(32);
	ft_putstr("  ");
}

void	out_rng(t_data *file, t_space size)
{
	int		min;
	int		max;

	min = (int)ft_strlen(ft_itoa(MINN(file->dev)));
	max = (int)ft_strlen(ft_itoa(MAXX(file->dev)));
	ft_putnbr(MAXX(file->dev));
	while (max < size.max--)
		ft_putchar(32);
	ft_putstr(", ");
	ft_putnbr(MINN(file->dev));
	while (min < size.min--)
		ft_putchar(32);
	ft_putchar(32);
}
