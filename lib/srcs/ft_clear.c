/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:46:53 by tmaselem          #+#    #+#             */
/*   Updated: 2020/07/23 13:03:09 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_clear(char **bits_pcs, size_t len)
{
	while (len--)
		ft_strdel(&bits_pcs[len]);
	ft_strdel(bits_pcs);
}
