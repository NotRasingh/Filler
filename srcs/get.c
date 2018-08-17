/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 12:13:17 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/17 11:12:07 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	ft_getplayer(void)
{
	static char		letter;
	char			*line;

	if (!letter)
	{
		get_next_line(0, &line);
		while (*line)
		{
			if (*line == '1')
				letter = 'O';
			else if (*line == '2')
				letter = 'X';
			line++;
		}
	}
	return (letter);
}

t_map	ft_init(t_map map, char **line)
{
	char	**tmp;

	tmp = ft_strsplit(*line, ' ');
	map.y = ft_atoi(tmp[1]);
	map.x = ft_atoi(tmp[2]);
	map.arr = (char**)malloc(sizeof(char*) * map.y + 1);
	return (map);
}

char	**ft_replace(char **map)
{
	int		i;
	int		j;
	char	letter;

	i = 0;
	j = 0;
	letter = ft_getplayer();
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == letter || map[i][j] == letter - 32)
				map[i][j] = 'k';
			j++;
		}
		i++;
	}
	return (map);
}

void	ft_getpiece(char **line, t_map map)
{
	static t_map	piece;
	int				j;
	char			**tmp;

	j = 0;
	if (!piece.arr)
		piece = ft_init(piece, line);
	tmp = ft_strsplit(*line, ' ');
	piece.y = ft_atoi(tmp[1]);
	piece.x = ft_atoi(tmp[2]);
	while (j < piece.y)
	{
		get_next_line(0, line);
		piece.arr[j] = *line;
		j++;
	}
	ft_place(map, piece);
}

void	ft_getmap(char **line)
{
	static t_map	map;
	int				j;

	j = 0;
	if (!map.arr)
		map = ft_init(map, line);
	while (line[0][0] != ' ')
		get_next_line(0, line);
	while (j <= map.y)
	{
		get_next_line(0, line);
		if (line[0][0] == 'P')
			break ;
		map.arr[j] = ft_strsub(*line, 4, map.x);
		j++;
	}
	map.arr = ft_replace(map.arr);
	ft_getpiece(line, map);
}
