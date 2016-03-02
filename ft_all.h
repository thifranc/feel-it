/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:47:30 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/02 14:13:41 by dgameiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALL_H
# define FT_ALL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_list
{
	int				x[4];
	int				y[4];
	int				pos[2];
	int				x_max;
	int				y_max;
	char			letter;
	struct s_list	*next;
	struct s_list	*prev;
}					t_tri;

void				ft_prt(t_tri *lol);
int					ft_translate(t_tri **tetri);
int					ft_tri_size(t_tri *tetri);
char				**ft_create_sqr(int len);
void				ft_actualise(char **map, t_tri *tetri, int *cur);
int					ft_formula(int nb_tetri);
void				ft_print(char **map, int len);
void				ft_get_area(t_tri *tetri, int len);
void				ft_find_sqr(char **map, t_tri *beg, int len);
void				ft_is_valid(char **map, t_tri *tetri, int *cur, int flag);
int					*ft_get_cur(int *cur, t_tri *tetri);
int					ft_bloc_test(char **map, t_tri *tetri, int *cur);
t_tri				*ft_clear(char **map, t_tri *tetri, int *cur);
int					ft_map_error(void);
t_tri				*ft_create_elem(void);
void				ft_tri_push_back(t_tri **begin_list);
int					ft_min(int *tab);
int					ft_max(int *tab);
void				ft_get_pos(int x, int y, int i, t_tri *tetri);
int					ft_get_tetri(char *str, t_tri *tmp);
int					ft_tetri_ctrl(t_tri *tetri, int count, int i);
int					ft_hash_nb(char *str);
int					ft_wild_cases(char *str, t_tri *tetri);
#endif
