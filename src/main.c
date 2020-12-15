/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:06:14 by kplums            #+#    #+#             */
/*   Updated: 2020/01/20 20:02:07 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	int		fd;
	int		size;
	t_map	map;
	t_tets	tet[26];

	if (ac != 2)
	{
		ft_putstr("usage: ./fillitold input_file\n");
		return (0);
	}
	if (((fd = open(av[1], O_RDONLY)) < 1) || \
	((size = ft_sizemat(\
	map.count = ft_validfile(fd, &tet[0]))) == 0))
	{
		ft_putstr("error\n");
		return (0);
	}
	map.size = size;
	fillit(&map, &tet[0]);
	return (0);
}
