/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizemat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kplums <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:04:54 by kplums            #+#    #+#             */
/*   Updated: 2020/01/20 19:55:00 by sdonya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	ft_sizemat(int n)
{
	int size;

	size = 4;
	if (n == 0)
		return (0);
	if (n < 3)
		return (3);
	while (size * size < n * 4)
		size++;
	return (size);
}
