/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:46:53 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/09 14:14:40 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>
///////////////////////////////////////////////////////////////////////////
//LOCATING CHARS
char	ft_find(char *line)
{
	int		ret;
	char	letter;

	ret = 1;
	letter = '\0';
	while (ret)
	{
		ret = get_next_line(0, &line);
		if (ft_strcmp(line, "$$$ exec p1 : [../a.out]") == 0)
		{
			letter = 'O';
			break ;
		}
		if (ft_strcmp(line, "$$$ exec p2 : [../a.out]") == 0)
		{
			letter = 'X';
			break ;
		}
	}
	return (letter);
}

//////////////////////////////////////////////////////////////////////////////////
//GETTING PIECE & MAP//
char	**ft_getmap(char *line, char **map, int max)
{
	int	ret;
	int	i;
	int	j;

	j = 0;
	ret = 1;
	ret = get_next_line(0, &line);
	while (ret && j < max)
	{
		ret = get_next_line(0, &line);
		i = 0;
		while (line[i] != '.' && line[i] != 'X' && line[i] != 'x'
				&& line[i] != 'O' && line[i] != 'o')
			i++;
		map[j] = ft_strsub(line, i, ft_strlen(line) - i);
		j++;
	}
	return (map);
}

char	**ft_getpiece(char *line, char **piece, int max)
{
	int	ret;
	int	j;

	j = 0;
	while (j < max - 0 && ret)
	{
		ret = get_next_line(0, &line);
		piece[j] = line;
		j++;
	}
	return (piece);
}

t_map	ft_mapsize(char *line)
{
	char	**tmp;
	t_map	map;

	if ((tmp = ft_strsplit(ft_strstr(line, "Plateau"), ' ')))
	{
		map.y = ft_atoi(tmp[1]);
		map.x = ft_atoi(tmp[2]);
	}
	map.arr = (char**)malloc(sizeof(map) * map.y + 1);
	map.arr = ft_getmap(line, map.arr, map.y);
	return (map);
}

t_map	ft_piecesize(char *line)
{
	t_map	piece;
	char	**tmp;
	if ((tmp = ft_strsplit(ft_strstr(line, "Piece"), ' ')))
	{
		piece.y = ft_atoi(tmp[1]);
		piece.x = ft_atoi(tmp[2]);
	}
	piece.arr = (char**)malloc(sizeof(piece) * piece.y);
	piece.arr = ft_getpiece(line, piece.arr, piece.y);
	return (piece);
}
/////////////////////////////////////////////////////////////////////////////////////
t_map	ft_replace(t_map map, char letter)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.arr[i][j] == letter || map.arr[i][j] == letter - 32)
			{
				map.arr[i][j] = 'k';
			}
			j++;
		}
		i++;
	}
	return (map);
}

int	ft_dist(t_map map, t_arrcount place)
{
	int	i;
	int	*dist;
	t_arrcount ma;

	dist = (int*)malloc(100 * sizeof(int*));
	ma.y = -1;
	i = -1;
	while (ma.y++ < map.y - 1)
	{
		ma.x = -1;
		while (ma.x++ < map.x - 1)
		{
			if (map.arr[ma.y][ma.x] != 'k' && map.arr[ma.y][ma.x] != '.' && ft_isalpha(map.arr[ma.y][ma.x]))
			{
				dist[i++] = abs(ma.y - place.y) + abs(ma.x - place.x);
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
	if (i > 0)
		dprintf(2, "\n\n\n<<<I: %d>>>\n\n\n---------------------", i);
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
//	dprintf(2, "\n\n\nFINAL: <%d> <%d>\n\n\n", place[0].y, place[0].x);
	dprintf(1, "%d %d\n", place[0].y, place[0].x);
}

void	ft_place(t_map map, t_map piece)
{
	t_arrcount	*possible;
	t_arrcount	ma;
	int	count;
	int	*dist;

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
//				dprintf(2, "\n\n\n<<<MAP: %d %d>>>\n\n\n",ma.y, ma.x);
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
/////////////////////////////////////////////////////////////////////////////////////
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
		letter = ft_find(line);
	while (ret)
	{
	//	dprintf(2, "\n\n\n\n\n\n\nLINE: <<<< %s >>>> \n\n\n\n\n\n\n\n", line);
		if (ft_strnequ(line, "Plateau", 7))	
		{	
			map = ft_mapsize(line);
	//		dprintf(2, "\n\n\n<<<1>>>--------------------------------------------------------------------------------------\n\n\n");
		}
		if (ft_strnequ(line, "Piece", 5))
		{
			piece = ft_piecesize(line);
			dprintf(2, "\n\n\n<<< BEFORE: >>>\n\n\n");
			ft_putarr(map.arr);
			dprintf(2, "\n\n\nAFTER:\n\n\n");
			map = ft_replace(map, letter);	
			dprintf(2, "\n\n\n<<< MAP: >>>\n\n\n");
			ft_putarr(map.arr);
			dprintf(2, "\n\n\nEND\n\n\n");
//			dprintf(2, "\n\n\n<<<1>>>------------------------------------\n\n\n");
//			dprintf(2, "\n\n\n<<<2>>>------------------------------------\n\n\n");
			ft_place(map, piece);
//			dprintf(2, "\n\n\n<<<3>>>------------------------------------\n\n\n");
//			dprintf(2, "\n\n\n<<<FT_PLACE>>>\n\n\n");
		}
		ret = get_next_line(0, &line);
	}
	return (0);
}
