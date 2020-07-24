/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:32:26 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/24 13:32:05 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		dis_perm(t_data *data)
{
	ft_putchar((S_ISFIFO(data->mode)) ? 112 : 0);
	ft_putchar((S_ISCHR(data->mode)) ? 99 : 0);
	ft_putchar((S_ISDIR(data->mode)) ? 100 : 0);
	ft_putchar((S_ISBLK(data->mode)) ? 98 : 0);
	ft_putchar((S_ISREG(data->mode)) ? 45 : 0);
	ft_putchar((S_ISLNK(data->mode)) ? 108 : 0);
	ft_putchar((S_ISSOCK(data->mode)) ? 115 : 0);
	ft_putchar((data->mode & S_IRUSR) ? 114 : 45);
	ft_putchar((data->mode & S_IWUSR) ? 119 : 45);
	ft_putchar((data->mode & S_IXUSR) ? 120 : 45);
	ft_putchar((data->mode & S_IRGRP) ? 114 : 45);
	ft_putchar((data->mode & S_IWGRP) ? 119 : 45);
	ft_putchar((data->mode & S_IXGRP) ? 120 : 45);
	ft_putchar((data->mode & S_IROTH) ? 114 : 45);
	ft_putchar((data->mode & S_IWOTH) ? 119 : 45);
	ft_putchar((data->mode & S_IXOTH) ? 120 : 45);
	ft_putstr("  ");
}

void			ft_ls(t_flag opt, t_data *files)
{
	t_data	*data;

	data = files;
	while (data)
	{
		if (!(opt.opt_a == false && data->file<:0:> == 46))
			ft_putendl(data->file);
		data = data->next;
	}
}

void			ft_ls_lg(t_flag opt, t_data *data, t_space size)
{
	dis_perm(data);
	dis_num(data->link, size.lsize);
	if (opt.opt_g == false)
	{
		if (getpwuid(data->user))
			output(getpwuid(data->user)->pw_name, size.usize);
		else
			output(ft_itoa(data->user), size.usize);
	}
	if (getgrgid(data->group))
		output(getgrgid(data->group)->gr_name, size.gsize);
	else
		output(ft_itoa(data->group), size.gsize);
	if (S_ISCHR(data->mode) || S_ISBLK(data->mode))
		out_rng(data, size);
	else
		dis_num(data->size, size.size);
	dis_time(data->time);
	ft_putendl(data->file);
}

void			ft_ls_la(t_flag opt, t_data *files, t_bool is_dir)
{
	t_data	*data;
	t_space	size;

	data = files;
	size = get_size(opt, files);
	if (is_dir)
	{
		ft_putstr("total ");
		ft_putnbr(size.total);
		ft_putchar(10);
	}
	while (data)
	{
		if (!(opt.opt_a == false && data->file<:0:> == 46))
			ft_ls_lg(opt, data, size);
		data = data->next;
	}
}
