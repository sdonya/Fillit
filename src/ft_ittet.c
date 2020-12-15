/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ittet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonya <sdonya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:05:26 by sdonya            #+#    #+#             */
/*   Updated: 2020/01/20 19:55:00 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_itvalidtet(char *str)
{
	int		i;
	int		reshetka;

	i = 0;
	reshetka = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (i == 20 && str[i] != '\n')
			return (0);
		if (i % 5 != 4 && str[i] != '#' && str[i] != '.' && i != 20)
			return (0);
		if (i % 5 == 4 && str[i] != '\n')
			return (0);
		if (str[i] == '#')
			reshetka++;
		i++;
	}
	if (i < 20 || reshetka != 4)
		return (0);
	return (1);
}

int			ft_ittet(char *str)
{
	int		i;
	int		flag;

	if (ft_itvalidtet(str) == 0)
		return (0);
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				flag++;
			if (i > 0 && str[i - 1] == '#')
				flag++;
			if (i < 15 && str[i + 5] == '#')
				flag++;
			if (i > 4 && str[i - 5] == '#')
				flag++;
		}
		i++;
	}
	return (flag == 6 || flag == 8);
}
