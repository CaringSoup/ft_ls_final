/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:39:25 by gferreir          #+#    #+#             */
/*   Updated: 2020/07/23 13:23:29 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_word_count(char const *s, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_lett_count(char const *s, char c, size_t i)
{
	size_t		fuk;

	fuk = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		fuk++;
	}
	return (fuk);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		this_shit;
	char		**ret;

	if (!s)
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	this_shit = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(ret[this_shit] = ft_strsub(s, i, ft_lett_count(s, c, i))))
				return (NULL);
			i += ft_lett_count(s, c, i);
			this_shit++;
		}
		else
			i++;
	}
	ret[this_shit] = NULL;
	return (ret);
}
