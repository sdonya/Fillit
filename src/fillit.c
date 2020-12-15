/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:10:25 by kplums            #+#    #+#             */
/*   Updated: 2020/01/20 20:02:07 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_b_zero_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->size - 1)
	{
		while (j < map->size - 1)
		{
			ft_putchar(map->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

void	ft_fig_size(t_tets *fig, t_map *map, int k)
{
	int	i;
	int	j;

	k = 0;
	fig[k].h = 0;
	fig[k].w = 0;
	while (k < map->count)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (fig[k].tet[i][j] == '#')
				{
					fig[k].h = fig[k].h <= i ? i + 1 : fig[k].h;
					fig[k].w = fig[k].w <= j ? j + 1 : fig[k].w;
				}
				j++;
			}
			i++;
		}
		k++;
	}
}

void	fillit(t_map *map, t_tets *tet)
{
	int k;

	k = 0;
	ft_b_zero_map(map);
	ft_fig_size(tet, map, k);
	while (ft_work_fi(map, tet, 0) == 0)
	{
		map->size++;
		ft_b_zero_map(map);
	}
	ft_print_map(map);
}
