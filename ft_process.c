/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:04:53 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/28 17:31:03 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

void	ft_is_valid(char **map, t_tri *tetri, int *cur, int len)
{
	while (tetri)
	{
		ft_get_area(tetri, len);
		if (ft_bloc_test(map, tetri, cur))
			tetri = tetri->next;
		else
		{
			cur = ft_get_cur(cur, tetri);
			if (cur[1] > tetri->y_max)
			{
				if (tetri->letter == 'A')
				{
					free(map);
					map = ft_create_sqr(++len);
					cur[0] = tetri->x[0];
					cur[1] = 0;
				}
				else
				{
					tetri = ft_clear(map, tetri, cur);
				}
			}
		}
	}
	ft_print(map, len);
}

int		*ft_get_cur(int *cur, t_tri *tetri)
{
	cur[0]++;
	if (cur[0] > tetri->x_max)
	{
		cur[1]++;
		cur[0] = tetri->x[0];
	}
	return (cur);
}

t_tri	*ft_clear(char **map, t_tri *tetri, int *cur)
{
	int	i;
	int	x;

	i = 0;
	cur[0] = tetri->prev->pos[0];
	cur[1] = tetri->prev->pos[1];
	x = tetri->prev->x[0];
	map[cur[1]][cur[0]] = '.';
	while (i++ < 3)
		map[cur[1] + tetri->prev->y[i]][cur[0] + tetri->prev->x[i] - x] = '.';
	ft_get_cur(cur, tetri->prev);
	return (tetri->prev);
}

void	ft_actualise(char **map, t_tri *tetri, int *cur)
{
	int		i;
	char	c;

	i = 0;
	c = tetri->letter;
	tetri->pos[0] = cur[0];
	tetri->pos[1] = cur[1];
	map[cur[1]][cur[0]] = c;
	while (i++ < 3)
		map[cur[1] + tetri->y[i]][cur[0] + tetri->x[i] - tetri->x[0]] = c;
	cur[0] = 0;
	cur[1] = 0;
}

int		ft_bloc_test(char **map, t_tri *tetri, int *cur)
{
	int	x;

	x = tetri->x[0];
	if (tetri->x_max < 0 || tetri->y_max < 0 || cur[1] > tetri->y_max)
		return (0);
	if (map[cur[1]][cur[0]] == '.'
			&& map[cur[1] + tetri->y[1]][cur[0] + tetri->x[1] - x] == '.'
			&& map[cur[1] + tetri->y[2]][cur[0] + tetri->x[2] - x] == '.'
			&& map[cur[1] + tetri->y[3]][cur[0] + tetri->x[3] - x] == '.')
	{
		ft_actualise(map, tetri, cur);
		return (1);
	}
	else
		return (0);
}
