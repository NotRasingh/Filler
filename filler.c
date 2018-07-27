/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:46:53 by rasingh           #+#    #+#             */
/*   Updated: 2018/07/27 11:53:08 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>
///////////////////////////////////////////////////////////////////////////
//PLACING PIECE

///SEGFAULT SOMEWHERE HERE

/*t_arrcount	ft_locatenextx(t_map map, t_arrcount x)
{
	int	j;
	t_arrcount y;

	j = x.x;
	y.y = 0;
	y.x = 0;
	while (x.y < map.y)
	{
		x.x = j;
		while (x.x < map.x)
		{
			if (map.arr[x.y][x.x] == 'X' || map.arr[x.y][x.x] == 'x')
			{
				y.x = x.x;
				y.y = x.y;
				break;
			}
			x.x++;
		}
		if (y.x || y.y)
			break;
		x.y++;
	}
	return (y);
}*/

t_arrcount	ft_nextstar(t_arrcount st, t_map piece)
{
	int	j;

	j = st.x;
	while (st.y < piece.y)
	{
		st.x = j;
		while (st.x < piece.x)
		{
			if (piece.arr[st.y][st.x] == '*')
				return (st);
			st.x++;
		}
		st.y--;
	}
	return (st);
}

void	ft_spacex(t_map map, t_map piece)// STILL NEED TO CHECK FOWARD
{
	t_arrcount	x;
	t_arrcount	st;
	t_arrcount	tmp;
	t_arrcount	cnt;

//	 dprintf(2, "\n\n\n<<4>>\n\n\n");
	x = ft_firstx(map);	
	tmp.x = x.x;
	st = ft_firststar(piece);
	cnt = st;
	tmp.y = st.x;
/*	while (cnt.y >= 0)
	{
		x.x = tmp.x;
		cnt.x = tmp.y;
		while (cnt.x >= 0)
		{
			if (map.arr[x.y][x.x] != '.' && piece.arr[cnt.y][cnt.x] == '*')
			{
				st = ft_nextstar(st, piece);
				cnt = st;
				tmp.x = st.x;
				x = ft_firstx(map);
				tmp.x = x.x;
			}
			cnt.x--;
		}
		cnt.y--;
	}*/
//	 dprintf(2, "\n\n\n<%d><%d>\n\n\n", st.y, st.x);
	 ft_placex(st, x);
}

void	ft_placex(t_arrcount pi, t_arrcount x)
{
		dprintf(2, "\n\n\n<%d><%d>\n\n\n", x.y, x.x);
	while (pi.y > 0)
	{
		x.y--;
		pi.y--;
	}
	while (pi.x > 0)
	{
		x.x--;
		pi.x--;
	}
	 dprintf(2, "\n\n\n<%d><%d>\n\n\n", x.y, x.x);
	 dprintf(1, "%d %d\n", x.y, x.x);
/*	ft_putnbr(x.y);
	ft_putchar(' ');
	ft_putnbr(x.x);
	ft_putchar('\n');*/
}
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

t_arrcount	ft_lastO(t_map map)
{
	t_arrcount	find;
	int		i;
	int		j;

	find.x = 0;
	find.y = 0;
	i = map.y - 1;
	while(i >= 0)
	{
		j = map.x - 1;
		while (j >= 0)
		{
			if (map.arr[i][j] == 'O' || map.arr[i][j] == 'o')
			{
				find.x = j;
				find.y = i;
				return (find);
			}
			j--;
		}
		i--;
	}
	return (find);
}

t_arrcount	ft_firstx(t_map map)
{
	t_arrcount	find;
	int		i;
	int		j;

	i = 0;
	find.x = 0;
	find.y = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			if (map.arr[i][j] == 'X' || map.arr[i][j] == 'x')
			{
				find.x = j;
				find.y = i;
				return (find);
			}
			j++;
		}
		i++;
	}
	return (find);
}

t_arrcount	ft_laststar(t_map piece)
{
	t_arrcount	star;
	char	*str;
	int		i;

	star.y = 0;
	i = piece.y - 1;
	while (i >= 0)
	{
		if ((str = ft_strrchr(piece.arr[i], '*')) != NULL)
		{
			star.y = i;
			star.x = piece.x - ft_strlen(str);
			return(star);
		}
		i--;
	}
	return(star);
}

t_arrcount	ft_firststar(t_map piece)
{
	t_arrcount	star;
	char	*str;
	int		i;

	star.y = 0;
	i = 0;
	while (i < piece.y)
	{
		if ((str = ft_strchr(piece.arr[i], '*')) != NULL)
		{
			star.y = i;
			star.x = piece.x - ft_strlen(str);
			return(star);
		}
		i++;
	}
dprintf(2, "\n\n\n<%d><%d>\n\n\n", star.y, star.x);	
	return(star);
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
//	dprintf(2, "\n\n\n<<6>>\n\n\n");
	ret = get_next_line(0, &line);
	while (j < max)
	{
		 dprintf(2, "\n\n\n<<7>>\n\n\n");
		piece[j] = line;
		j++;
		ret = get_next_line(0, &line);
	}
	 dprintf(2, "\n\n\n<<8>>\n\n\n");
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
//	 dprintf(2, "\n\n\n<<3>>\n\n\n");
	if ((tmp = ft_strsplit(ft_strstr(line, "Piece"), ' ')))
	{
		piece.y = ft_atoi(tmp[1]);
		piece.x = ft_atoi(tmp[2]);
	}
//	 dprintf(2, "\n\n\n<<4>>\n\n\n");
	piece.arr = (char**)malloc(sizeof(piece) * piece.y);
//	 dprintf(2, "\n\n\n<<5>>\n\n\n");
	piece.arr = ft_getpiece(line, piece.arr, piece.y);
//	 dprintf(2, "\n\n\n<<9>>\n\n\n");
	return (piece);
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
		if (ft_strnequ(line, "Plateau", 7))	
			map = ft_mapsize(line);
//		 dprintf(2, "\n\n\n<<1>>\n\n\n");
		if (ft_strnequ(line, "Piece", 5))
		{
//			 dprintf(2, "\n\n\n<<2>>\n\n\n");
			piece = ft_piecesize(line);	
			 dprintf(2, "\n\n\n<<10>>\n\n\n");
			if (letter == 'X')
				ft_spacex(map, piece);
			//	else
			//		ft_placeo(map, piece); 
		}
		ret = get_next_line(0, &line);
	}
	return (0);
}
