/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:14:25 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/24 13:24:04 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	pro_erro(char opt)
{
	ft_putstr_fd("ft_ls: You have either selected an invalid option or it is under construction -", 2);
	ft_putchar_fd(opt, 2);
	ft_putstr_fd("\nvalid inputs: ft_ls -[larRt]\n", 2);
	exit(1);
}

void	space_errors(t_space *size, t_data *cur)
{
	if (getpwuid(cur->user))
		size->usize = (int)ft_strlen(getpwuid(cur->user)->pw_name) \
			> size->usize ? (int)ft_strlen(getpwuid(cur->user)->pw_name) \
			: size->usize;
	else
		size->usize = (int)ft_strlen(ft_itoa(cur->user)) \
			> size->usize ? (int)ft_strlen(ft_itoa(cur->user)) \
			: size->usize;
	if (getgrgid(cur->group))
		size->gsize = (int)ft_strlen(getgrgid(cur->group)->gr_name) \
			> size->gsize ? \
			(int)ft_strlen(getgrgid(cur->group)->gr_name) : size->gsize;
	else
		size->gsize = (int)ft_strlen(ft_itoa(cur->group)) \
			> size->gsize ? (int)ft_strlen(ft_itoa(cur->group)) \
			: size->gsize;
}

void	clean_up(t_data **dirt)
{
	while (*dirt)
	{
		ft_strdel(&((*dirt)->file));
		ft_strdel(&((*dirt)->path));
		free(*dirt);
		*dirt = (*dirt)->next;
	}
}
