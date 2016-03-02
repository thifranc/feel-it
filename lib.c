/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:58:21 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/29 18:25:37 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

int		ft_map_error(void)
{
	write(1, "error\n", 6);
	return (0);
}

t_tri	*ft_create_elem(void)
{
	t_tri *list;

	if (!(list = (t_tri*)malloc(sizeof(t_tri))))
		return (0);
	else
	{
		list->next = NULL;
		list->prev = NULL;
	}
	return (list);
}

void	ft_tri_push_back(t_tri **begin_list)
{
	t_tri	*tmp;

	if (*begin_list == NULL)
		*begin_list = ft_create_elem();
	else if (((*begin_list)->next) == NULL)
	{
		(*begin_list)->next = ft_create_elem();
		tmp = (*begin_list)->next;
		tmp->prev = *begin_list;
	}
	else
		ft_tri_push_back(&((*begin_list)->next));
}

int		ft_min(int *tab)
{
	int	min;
	int	i;

	i = 1;
	min = tab[0];
	while (i < 4)
	{
		if (min > tab[i])
			min = tab[i];
		i++;
	}
	return (min);
}

int		ft_max(int *tab)
{
	int	max;
	int	i;

	i = 1;
	max = tab[0];
	while (i < 4)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}
