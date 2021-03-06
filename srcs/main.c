/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:31:21 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/24 13:30:51 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		resolve(t_list *path, t_bool is_dirs, t_flag opt)
{
	DIR		*dir;
	t_list	*lst[3];

	lst[0] = NULL;
	lst[1] = NULL;
	lst[2] = path;
	while (lst[2])
	{
		if ((dir = opendir(lst[2]->content)) == NULL)
			errno != ENOTDIR ? nerror("ft_ls: ", lst[2]->content, 0) : \
				ft_lstpshbck(&lst[0], lst[2]->content, lst[2]->content_size);
		else
		{
			ft_lstpshbck(&lst[1], lst[2]->content, lst[2]->content_size);
			if (closedir(dir) == -1)
				nerror("ft_ls: ", lst[2]->content, 0);
		}
		lst[2] = lst[2]->next;
	}
	lst[0] ? eva_names(opt, lst[0]) : NULL;
	lst[0] && lst[1] ? (void)ft_putchar(10) : NULL;
	lst[1] ? ft_ls_ld(opt, lst[1], is_dirs) : NULL;
	ft_lstdel(&lst[0], &del);
	ft_lstdel(&lst[1], &del);
}

int				main(int ac, char **av)
{
	t_flag	opt;
	t_list	*path;

	opt = (t_flag){false, false, false, false, false, false, false, false};
	path = NULL;
	if (ac > 1)
		get_opt(ac - 1, av, &path, &opt);
	if (path == NULL)
		path = ft_lstnew(".", ft_strlen("."));
	resolve(path, path->next != NULL ? true : false, opt);
	ft_lstdel(&path, &del);
	return (0);
}
