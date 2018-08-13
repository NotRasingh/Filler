/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:46:53 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/13 14:56:42 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>
///////////////////////////////////////////////////////////////////////////                     1
//LOCATING CHARS
char	ft_find(char **line)
{
	int		ret;
	char	letter;

	ret = 1;
	letter = '\0';
	while (ret)
	{
		ret = get_next_line(0, line);
		if (ft_strcmp(*line, "$$$ exec p1 : [../a.out]") == 0)
		{
			letter = 'O';
			break ;
		}
		if (ft_strcmp(*line, "$$$ exec p2 : [../a.out]") == 0)
		{
			letter = 'X';
			break ;
		}
	}
	return (letter);
}

//////////////////////////////////////////////////////////////////////////////////              4
//GETTING PIECE & MAP//
char	**ft_getmap(char **line, char **map, int max)
{
	int	ret;
	//	int	i;
	int	j;

	j = 0;
	ret = 1;
	ret = get_next_line(0, line);
	while (ret && j < max)
	{
		ret = get_next_line(0, line);
		dprintf(2, "!TEST\n\n\n");
		while (**line != '.' && **line != 'X' && **line != 'x'
				&& **line != 'O' && **line != 'o')
			**line++;
		map[j] = *line;
		dprintf(2, "MAP: %s\n\n", map[j]);
		j++;
		dprintf(2, "%d\n\n\n", j);
	}
	dprintf(2, "TEST\n\n\n");
	return (map);
}

char	**ft_getpiece(char **line, char **piece, int max)
{
	int	ret;
	int	j;

	j = 0;
	while (j < max && ret)
	{
		ret = get_next_line(0, line);
		piece[j] = *line;
		j++;
	}
	return (piece);
}

t_map	ft_mapsize(char **line)
{
	char	**tmp;
	t_map	map;

	dprintf(2, "\n-----------------------------------------\n");
	dprintf(2, "TESTLINE : <<<%s>>>\n\n\n", *line);
	dprintf(2, "\n-----------------------------------------\n");
	if ((tmp = ft_strsplit(ft_strstr(*line, "Plateau"), ' ')))
	{
		map.y = ft_atoi(tmp[1]);
		map.x = ft_atoi(tmp[2]);
	}
	dprintf(2, "\n-----------------------------------------\n");
	map.arr = (char**)malloc(sizeof(map) * map.y + 1);
	dprintf(2, "\nMALLOC-----------------------------------------\n");
	map.arr = ft_getmap(line, map.arr, map.y);
	dprintf(2, "\nMAP-----------------------------------------\n");
	return (map);
}

t_map	ft_piecesize(char **line)
{
	t_map	piece;
	char	**tmp;
	dprintf(2, "\n-----------------------------------------\n");
	dprintf(2, "TESTLINE : <<<%s>>>\n\n\n", *line);
	if ((tmp = ft_strsplit(ft_strstr(*line, "Piece"), ' ')))
	{
		piece.y = ft_atoi(tmp[1]);
		piece.x = ft_atoi(tmp[2]);
	}
	dprintf(2, "\n-----------------------------------------\n");
	piece.arr = (char**)malloc(sizeof(piece) * piece.y);
	dprintf(2, "\nMALLOC-----------------------------------------\n");
	piece.arr = ft_getpiece(line, piece.arr, piece.y);
	return (piece);
}
/////////////////////////////////////////////////////////////////////////////////////                    5
char	**ft_replace(char **arr, char letter)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == letter || arr[i][j] == letter - 32)
			{
				arr[i][j] = 'k';
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	ft_dist(t_map map, t_arrcount place)
{
	int	i;
	int	*dist;
	t_arrcount ma;

	dist = (int*)malloc(100 * sizeof(int));
	ma.y = -1;
	i = -1;
	while (ma.y++ < map.y - 1)
	{
		ma.x = -1;
		while (ma.x++ < map.x - 1)
		{
			if (map.arr[ma.y][ma.x] != 'k' && map.arr[ma.y][ma.x] != '.' && ft_isalpha(map.arr[ma.y][ma.x]))
			{
				dist[i++] = abs((ma.y - place.y) + (ma.x - place.x));
			}
		}
	}
	ft_sort_int_tab(dist, i);
	return (dist[0]);
}

int	ft_move(t_map map, t_arrcount ma, t_map piece)
{
	t_arrcount	pi;
	int	tmp;
	int	i;

	tmp = ma.x;
	i = 0;
	pi.y = 0;
	while (pi.y <  piece.y && ma.y < map.y)
	{
		pi.x = 0;
		ma.x = tmp;
		while (pi.x < piece.x && ma.x < map.x)
		{
			if (map.arr[ma.y][ma.x] != 'k' && map.arr[ma.y][ma.x] != '.'  && piece.arr[pi.y][pi.x] == '*')
				return (0);
			else if (map.arr[ma.y][ma.x] == 'k' && piece.arr[pi.y][pi.x] == '*')
				i++;
			pi.x++;
			ma.x++;
		}
		pi.y++;
		ma.y++;
	}
	return (i);
}

void	ft_sort(int *tab, unsigned int size, t_arrcount *place)
{
	unsigned int    i;
	int 			tmp;
	t_arrcount		tmp2;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			tmp2 = place[i];
			place[i] = place[i + 1];
			place[i + 1] = tmp2;
			i = 0;
		}
	}
	dprintf(2, "\n\n\nFIINAL: <%d> <%d>\n\n\n", place[0].y, place[0].x);
	dprintf(1, "%d %d\n", place[0].y, place[0].x);
}

void	ft_place(t_map map, t_map piece)
{
	t_arrcount	*possible;
	t_arrcount	ma;
	int	count;
	int	*dist;

	dprintf(2, "\n\n\nSTART\n\n\n");
	ft_putarr(map.arr);
	dprintf(2, "\n\n\nEND\n\n\n");
	count = -1;
	ma.y = 0;
	possible = (t_arrcount*)malloc(sizeof(t_arrcount));
	dist = (int*)malloc(100 * sizeof(int));
	while (ma.y < map.y)
	{
		ma.x = 0;
		while (ma.x < map.x)
		{
			if (ft_move(map, ma, piece) == 1)
			{
				count++;
				possible[count].y = ma.y;
				possible[count].x = ma.x;
				dist[count] = ft_dist(map, possible[count]);
			}
			ma.x++;
		}
		ma.y++;
	}
	ft_sort(dist, count, possible);
}
/////////////////////////////////////////////////////////////////////////////////////    main.c
int		main(void)
{
	char		*line;
	int			ret;
	t_map		map;
	t_map		piece;
	static char	letter;

	line = NULL;
	ret = 1;
	if (!letter)
		letter = ft_find(&line);
	ret = get_next_line(0, &line);
	dprintf(2, "\n\n\nLINE: <<<%s>>>\n\n\n", line);
	map = ft_mapsize(&line);
	dprintf(2, "AFTERMAPLINE: <<<%s>>>\n", line);
	dprintf(2, "3\n");
	piece = ft_piecesize(&line);
	map.arr = ft_replace(map.arr, letter);
	ft_place(map, piece);
	dprintf(2, "\n\n\n------------END-----------\n\n\n");
	return (0);
}
