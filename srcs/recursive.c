/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 10:55:34 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/24 13:23:06 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ft_ls_rr_exce(t_flag opt, char *path)
{
	t_data	*data;
	DIR		*dir;

	data = NULL;
	ft_putchar(10);
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		while (get_data(&data, readdir(dir), \
					ft_strjoin(path, "/"), opt) != 0);
		closedir(dir);
		if (data)
			dis_name(opt, data, true);
		data = NULL;
	}
	else
		nerror("ft_ls: ", path, 0);
}

void	ft_ls_rr(t_flag opt, t_data *data)
{
	t_data	*data1;

	data1 = data;
	while (data1)
	{
		if (data1->file && data1->path && \
				S_ISDIR(data1->mode) && \
				ft_strcmp(".", data1->file) && \
				ft_strcmp("..", data1->file) && \
				!(opt.opt_a == false && data1->file<:0:> == 46))
			ft_ls_rr_exce(opt, data1->path);
		data1 = data1->next;
	}
}
