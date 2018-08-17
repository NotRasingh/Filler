/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:57:14 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/17 11:09:20 by rasingh          ###   ########.fr       */
/*   Updated: 2018/08/09 14:00:19 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"

typedef struct		s_map
{
	int				x;
	int				y;
	char			**arr;
}					t_map;

typedef struct		s_moves
{
	int				col;
	int				row;
	int				rating;
	struct s_moves	*next;
}					t_moves;

t_moves	*ft_make_list(t_map map, t_map piece);
void	ft_add_node(t_moves **head, int row, int col);
int		ft_isvalid(t_map map, t_map piece, int row, int col);
void	ft_distance(t_moves *moves, t_map map);
void    ft_rate(t_moves *moves, t_map map);

void	ft_print(t_moves *place);
void	ft_none(void);
void	ft_place(t_map map, t_map piece);
t_moves	*ft_best(t_moves *moves);

t_map	ft_init(t_map map, char **line);
char	**ft_replace(char **map);
char	ft_getplayer(void);
void	ft_getpiece(char **line, t_map map);
void	ft_getmap(char **line);

int		ft_play(void);

#endif
