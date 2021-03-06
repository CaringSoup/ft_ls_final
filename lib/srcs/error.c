/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 15:13:56 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:32:44 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	nerror(char *name, char *error, int e)
{
	ft_putstr_fd(name, 2);
	perror(error);
	if (e)
		exit(1);
}
