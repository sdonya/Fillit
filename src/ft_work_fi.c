/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_fi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdonya <sdonya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:00:41 by sdonya            #+#    #+#             */
/*   Updated: 2020/01/20 19:55:00 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	del_fig(t_map *map, t_tets fig, int i, int j)
{
	int	y;
	int	x;

	y = 0;
	while (y < fig.h)
	{
		x = 0;
		while (x < fig.w)
		{
			if (fig.tet[y][x] == '#')
			{
				map->map[i + y][j + x] = '.';
			}
			x++;
		}
		y++;
	}
}

void	put_fig(t_map *map, t_tets fig, int i, int j)
{
	int	y;
	int	x;

	y = 0;
	while (y < fig.h)
	{
		x = 0;
		while (x < fig.w)
		{
			if (fig.tet[y][x] == '#')
			{
				map->map[i + y][j + x] = fig.id;
			}
			x++;
		}
		y++;
	}
}

int		check_pos(t_map *map, t_tets fig, int i, int j)
{
	int	y;
	int	x;

	y = 0;
	while (y < fig.h)
	{
		x = 0;
		while (x < fig.w)
		{
			if (fig.tet[y][x] == '#' && map->map[i + y][j + x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	put_fig(map, fig, i, j);
	return (1);
}

int		ft_work_fi(t_map *map, t_tets *fig, int count)
{
	int	k;
	int	i;
	int	j;

	i = 0;
	if (count == map->count)
		return (1);
	while (i < (map->size - fig[count].h))
	{
		j = 0;
		while (j < (map->size - fig[count].w))
		{
			if (check_pos(map, fig[count], i, j) == 1)
			{
				k = count + 1;
				if (ft_work_fi(map, fig, k) == 1)
					return (1);
				else
					del_fig(map, fig[count], i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}
