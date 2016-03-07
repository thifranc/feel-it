/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:28:26 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/06 16:12:46 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

void	ft_print(char **map, int len)
{
	int	i;

	i = 0;
	while (map[i])
	{
		write(1, map[i], len + 1);
		i++;
	}
	free(map);
	map = NULL;
}

void	ft_get_area(t_tri *tetri, int len)
{
	tetri->x_max = len - (ft_max(tetri->x) - tetri->x[0]) - 1;
	tetri->y_max = len - ft_max(tetri->y) - 1;
}

void	ft_find_sqr(char **map, t_tri *beg, int len)
{
	int cur[2];

	cur[1] = 0;
	cur[0] = beg->x[0];
	ft_is_valid(map, beg, cur, len);
}
