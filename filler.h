/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:57:14 by rasingh           #+#    #+#             */
/*   Updated: 2018/07/27 10:01:51 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"

typedef struct	s_map
{
	int	x;
	int	y;
	char **arr;
}				t_map;

typedef struct	s_arrcount
{
	int	x;
	int	y;
}				t_arrcount;

char		**ft_getmap(char *line, char **map, int max);
char		ft_find(char *line);
char		**ft_getpiece(char *line, char **piece, int max);
t_map		ft_mapsize(char *line);
t_map		ft_piecesize(char *line);
t_arrcount	ft_firststar(t_map piece);
t_arrcount	ft_laststar(t_map piece);
t_arrcount	ft_firstx(t_map map);
t_arrcount	ft_lasto(t_map map);
void		ft_placex(t_arrcount pi, t_arrcount x);
void		ft_spacex(t_map map, t_map piece);
#endif
