/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Newfiller.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:26:24 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/14 16:21:34 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

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

void	ft_moves(t_map map, t_map piece)
{
	map.x = 0;
	piece.y = 0;
	return ;
}

void	ft_getpiece(char **line, t_map map)
{
	static t_map	piece;
	int				j;

	j = 0;
	if (!piece.arr)
		piece = ft_init(piece, line);
	dprintf(2, "TESTLINE <<%s>>\n\n", *line);
	while (j < piece.y)
	{
		get_next_line(0, line);
		piece.arr[j] = *line;
		dprintf(2, "PIECE <<%s>>\n", piece.arr[j]);
		j++;
	}
	ft_moves(piece, map);
}

void	ft_getmap(char **line)
{
	static t_map	map;
	int				j;

	j = 0;
	if (!map.arr)
		map = ft_init(map, line);
	get_next_line(0, line);
	dprintf(2, "TESTLINE <<%s>>\n\n", *line);
	while (1)
	{
		get_next_line(0, line);
		if (line[0][0] == 'P')
			break ;
		map.arr[j] = ft_strsub(*line, 4, map.x);
		dprintf(2, "MAP <<%s>>\n", map.arr[j]);
		j++;
	}
	map.arr = ft_replace(map.arr);
	dprintf(2, "AFTERMAPLINE: <<%s>>\n", *line);
	ft_getpiece(line, map);
	dprintf(2, "AFTERPIECELINE: <<%s>>\n", *line);
}

int		ft_play(void)
{
	char *line;

	if (get_next_line(0, &line))
	{
		dprintf(2, "LINE: %s\n\n", line);
		ft_getmap(&line);
		return (1);
	}
	return (0);
}

int		main(void)
{
	int		i;
	char	letter;

	i = 1;
	letter = ft_getplayer();
	while (i)
		i = ft_play();
	return (0);
}
