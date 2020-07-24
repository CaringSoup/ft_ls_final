/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:16:26 by gferreir          #+#    #+#             */
/*   Updated: 2018/06/21 14:35:12 by gferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_counter(char const *str, char c)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == '\0' || str[i + 1] == c))
			counter++;
		i++;
	}
	return (counter);
}
