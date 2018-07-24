/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:46:53 by rasingh           #+#    #+#             */
/*   Updated: 2018/07/24 14:20:13 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

char	**ft_getmap(char *line, char**map)
{
	int	ret;
	int	i;
	int	j;

	j = 0;
	ret = 1;
	while(ret && line[0] >= '0' && line[0] <= '9')/*(!ft_strnequ(line,"Piece", 5 ))*/
	{
		i = 0;
		while (line[i] != '.' && line[i] != 'X' && line[i] != 'x' 
				&& line[i] != 'O' && line[i] != 'o')
			i++;
		map[j] = ft_strsub(line, i, ft_strlen(line) - i);
		j++;
		ret = get_next_line(0, &line);
	}
	return (map);
}

char	ft_find(char *line)
{
	int		ret;
	char	letter;

	ret = 1;
	letter = '\0';
	while (ret)
	{
		ret = get_next_line(0, &line);
		if (ft_strcmp(line, "$$$ exec p1 : [../a.out]") == 0)  //////////////
		{
			letter = 'O';                                                 //   For    //
			break;
		}
		if (ft_strcmp(line, "$$$ exec p2 : [../a.out]") == 0)//    Char  //
		{	
			letter = 'X';                                              //////////////
			break;
		}
	}
	return (letter);
}

char	**ft_getpiece(char *line, char **piece, int max)
{
	int	ret;
	int	j;

	j = 0;
	ret = get_next_line(0, &line);
	while(j < max)
	{
		piece[j] = line;
		j++;
		ret = get_next_line(0, &line);
	}
	return (piece);
}

t_map	ft_mapsize(char *line)
{
	int		j;
	t_map	map;

	j = 0;
	map.x = 0;
	map.y = 0;
	while (line[j] < 48 || line[j] > 57)
		j++;
	map.y = ft_atoi(ft_strsub(line, j, 2));
	map.x = ft_atoi(ft_strsub(line, j + 3, 2));
	map.arr = (char**)malloc(sizeof(map) * map.y + 1);
	map.arr = ft_getmap(line, map.arr);
	return (map);
}

t_map	ft_piecesize(char *line)
{
	t_map	piece;
	char**	tmp;

	if ((tmp = ft_strsplit(ft_strstr(line, "Piece"), ' ')))
	{
		piece.y = ft_atoi(tmp[1]);
		piece.x = ft_atoi(tmp[2]);
	}
	piece.arr = (char**)malloc(sizeof(piece) * piece.y);
	piece.arr = ft_getpiece(line, piece.arr, piece.y);
	return (piece);
}

int	main()
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
		if (ft_strnequ(line, "Plateau", 7))
			map  = ft_mapsize(line);	//also used to get map  *WORKING*
		if (ft_strnequ(line, "Piece", 5))
		{
			piece = ft_piecesize(line); //also used to get piece
		}
		ret = get_next_line(0, &line);
		//ft_place(map, piece);
	}
	return (0);
}


