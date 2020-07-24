/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:29:01 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/24 13:30:22 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_ls_d(t_flag opt, t_data *dirlist, t_bool is_dirs)
{
	t_data	*files;
	t_extra stuff;

	stuff.it = false;
	files = NULL;
	while (dirlist)
	{
		stuff.dir = opendir(dirlist->file);
		stuff.tmp = ft_strjoin(dirlist->path, "/");
		while (get_data(&files, readdir(stuff.dir), stuff.tmp, opt) != false)
			;
		closedir(stuff.dir);
		if (files)
		{
			stuff.it == true ? (void)ft_putchar(10) : NULL;
			is_dirs ? ft_putendl(ft_strjoin(dirlist->file, ":")) : NULL;
			stuff.it = true;
			dis_name(opt, files, true);
		}
		clean_up(&files);
		dirlist = dirlist->next;
		ft_strdel(&(stuff.tmp));
	}
}

void			dis_name(t_flag opt, t_data *files, t_bool is_dir)
{
	t_data	*cur;

	cur = files;
	cur = sort_data(cur, opt);
	(opt.opt_l == true || opt.opt_g == true) ? \
				ft_ls_la(opt, cur, is_dir) : ft_ls(opt, cur);
	opt.opt_rr == true ? ft_ls_rr(opt, cur) : NULL;
}

void			ft_ls_ld(t_flag opt, t_list *path, t_bool is_dirs)
{
	t_list	*cur;
	t_data	*dirlist;

	cur = path;
	dirlist = NULL;
	while (cur)
	{
		get_data_lg(&dirlist, cur->content, "", opt);
		cur = cur->next;
	}
	dirlist = sort_data(dirlist, opt);
	ft_ls_d(opt, dirlist, is_dirs);
	free(dirlist->file);
	free(dirlist->path);
	free(dirlist);
}

void			eva_names(t_flag opt, t_list *path)
{
	t_list	*cur;
	t_data	*files;

	cur = path;
	files = NULL;
	opt.opt_a = true;
	while (cur)
	{
		get_data_lg(&files, cur->content, "", opt);
		cur = cur->next;
	}
	if (files)
		dis_name(opt, files, false);
}

void			del(void *content, size_t content_size)
{
	ft_memdel(&content);
	(void)content_size;
}
