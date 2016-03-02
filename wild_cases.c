/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:06:46 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/02 14:14:59 by dgameiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

void	ft_get_pos(int x, int y, int i, t_tri *tetri)
{
	tetri->x[i] = x;
	tetri->y[i] = y;
}

int		ft_get_tetri(char *str, t_tri *tmp)
{
	int	x;
	int	y;
	int	i;
	int	h_ct;

	y = 0;
	i = 0;
	h_ct = 0;
	while (i != 20)
	{
		x = 0;
		while (str[i] != '\n' && i != 20)
		{
			if (str[i] == '#')
			{
				ft_get_pos(x, y, h_ct, tmp);
				h_ct++;
			}
			i++;
			x++;
		}
		i++;
		y++;
	}
	return (ft_tetri_ctrl(tmp, 0, -1));
}

int		ft_tetri_ctrl(t_tri *tetri, int count, int i)
{
	int test_x;
	int test_y;
	int j;

	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			test_x = 0;
			test_y = 0;
			if (j == i && j < 3)
				j++;
			if (j != i)
			{
				test_x = tetri->x[i] - tetri->x[j];
				test_y = tetri->y[i] - tetri->y[j];
			}
			if (((test_x == 1 || test_x == -1) && test_y == 0) ||
				(test_x == 0 && (test_y == 1 || test_y == -1)))
				count++;
		}
	}
	return (count == 8 || count == 6);
}

int		ft_hash_nb(char *str)
{
	int	h_ct;
	int	i;
	int	l_ct;

	h_ct = 0;
	l_ct = 0;
	i = 0;
	while (i != 20 && (str[i] == '.' || str[i] == '#' || str[i] == '\n'))
	{
		if (str[i] == '\n' && i != 0 && (i - l_ct) % 4 == 0)
			l_ct++;
		if (str[i] == '#')
			h_ct++;
		i++;
	}
	if (l_ct != 4 || h_ct != 4 || str[i - 1] != '\n')
		return (0);
	return (h_ct);
}

int		ft_wild_cases(char *str, t_tri *tetri)
{
	int		fd;
	int		red;
	int		red2;
	char	*buf;

	if (!(buf = (char*)malloc(sizeof(char) * (20))))
		return (ft_map_error());
	if ((fd = open(str, O_RDONLY)) == -1)
		return (ft_map_error());
	red = read(fd, buf, 20);
	while (red == 20)
	{
		if (ft_hash_nb(buf) != 4 || ft_get_tetri(buf, tetri) == 0)
			return (ft_map_error());
		red2 = read(fd, buf, 1);
		if (buf[0] != '\n' && red2 == 1)
			return (ft_map_error());
		if ((red = read(fd, buf, 20)) == 20)
			ft_tri_push_back(&tetri);
		tetri = tetri->next;
	}
	free(buf);
	if (red == 0 && red2 == 0 && buf[0])
		return (fd);
	return (ft_map_error());
}
