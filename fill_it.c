/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:16:14 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/06 16:09:43 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

int		ft_translate(t_tri *tetri)
{
	int		i;
	int		size;
	int		x_min;
	int		y_min;
	t_tri	*cur;

	cur = tetri;
	size = 0;
	while (cur)
	{
		i = 0;
		x_min = ft_min(cur->x);
		y_min = ft_min(cur->y);
		while (i < 4)
		{
			cur->x[i] -= x_min;
			cur->y[i] -= y_min;
			i++;
		}
		cur->letter = 'A' + size;
		cur = cur->next;
		size++;
	}
	return (size);
}

char	**ft_create_sqr(int len)
{
	char	**out;
	int		i;
	int		x;

	i = -1;
	if (!(out = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (i++ < len)
		if (!(out[i] = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
	x = 0;
	while (x < len)
	{
		i = 0;
		while (i < len)
		{
			out[x][i] = '.';
			i++;
		}
		out[x][i] = '\n';
		x++;
	}
	out[x] = NULL;
	return (out);
}

int		ft_formula(int nb_tetri)
{
	int		sqr_rt;
	int		area;

	area = 4 * nb_tetri;
	sqr_rt = 1;
	while (sqr_rt * sqr_rt < area)
		sqr_rt++;
	return (sqr_rt);
}

int		main(int ac, char **av)
{
	char	**map;
	int		nb_tetri;
	t_tri	*beg;
	t_tri	*tmp;
	int		len;

	tmp = ft_create_elem();
	beg = tmp;
	if (ac == 2 && (len = ft_wild_cases(av[1], tmp)) != 0)
	{
		close(len);
		nb_tetri = ft_translate(beg);
		len = ft_formula(nb_tetri);
		map = ft_create_sqr(len);
		ft_find_sqr(map, beg, len);
	}
	if (ac != 2)
		write(1, "usage: ./fillit source_file (only one)\n", 39);
	return (0);
}
