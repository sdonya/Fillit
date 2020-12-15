/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 16:13:58 by kplums            #+#    #+#             */
/*   Updated: 2020/01/20 19:55:00 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_min(char *str, char c)
{
	int		i;
	int		min;

	i = 0;
	min = 3;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (c == '/' && min > i / 5)
				min = i / 5;
			else if (c == '%' && min > i % 5)
				min = i % 5;
		}
		i++;
	}
	return (min);
}

void		ft_puttchk(t_tets *tet)
{
	int		x;
	int		y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
			tet->tet[x][y++] = '.';
		x++;
	}
}

void		ft_koord(t_tets *tet, char *str, char id)
{
	int		i;
	int		min_y;
	int		min_x;

	i = 0;
	min_y = ft_min(str, '/');
	min_x = ft_min(str, '%');
	tet->id = id;
	ft_puttchk(tet);
	while (i < 21)
	{
		if (str[i] == '#')
			tet->tet[i / 5 - min_y][i % 5 - min_x] = str[i];
		i++;
	}
}

int			ft_validfile(int fd, t_tets *tets)
{
	char	buf[22];
	int		byteread;
	int		flag;
	char	proverka;
	char	id;

	id = 'A';
	flag = 0;
	while ((byteread = read(fd, &buf, 21)) > 0)
	{
		buf[byteread] = '\0';
		if (ft_ittet((char *)&buf) == 0)
			return (0);
		ft_koord(tets, (char *)&buf, id);
		proverka = buf[20];
		flag++;
		id++;
		tets++;
	}
	if (proverka == '\n')
		return (0);
	if (flag < 27 && flag > 0)
		return (flag);
	return (0);
}
