/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:10:56 by kplums            #+#    #+#             */
/*   Updated: 2020/01/20 20:07:28 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_map
{
	char		map[100][100];
	int			size;
	int			count;
}				t_map;

typedef struct	s_tets
{
	char		id;
	char		tet[4][4];
	int			h;
	int			w;
}				t_tets;

int				ft_sizemat(int n);
int				ft_validfile(int fd, t_tets *tets);
void			fillit(t_map *map, t_tets *tet);
int				ft_work_fi(t_map *map, t_tets *fig, int count);
int				ft_ittet(char *str);

#endif
