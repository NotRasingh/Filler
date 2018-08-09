/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:46:53 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/09 11:09:51 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>
///////////////////////////////////////////////////////////////////////////
//PLACING PIECE

//SEGFAULT WHEN REACHING END OF MAP
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
  }

  t_arrcount	ft_nextstar(t_arrcount st, t_map piece)
  {
  int	j;

  st.y--;
  st.x--;
  j = st.x;
  while (st.y >= 0)
  {
  st.x = j;
  while (st.x >= 0)
  {
  if (piece.arr[st.y][st.x] == '*')
  return (st);
  st.x--;
  }
  st.y--;
  }
  return (st);
  }

  void	ft_spacex(t_map map, t_map piece) //only counts backward from last star in piece (still need to count foraward to end of piece)
  {
  t_arrcount	st;
  t_arrcount	x;
  t_arrcount	tmp;
  t_arrcount	tmpx;
  int			cnt;

  cnt = 0;
  st = ft_laststar(piece);
  tmp = st;
//	dprintf(2, "\n\n\n<ST %d><%d>\n\n\n", st.y, st.x);
x = ft_firstx(map);
tmpx = x;
while (tmp.y >= 0)
{
tmp.x = st.x;
tmpx.x = x.x;
while (tmp.x >= 0)
{
tmpx.x--;
tmp.x--;
if (map.arr[tmpx.y][tmpx.x] != '.' && piece.arr[tmp.y][tmp.x] == '*' && cnt > 0 && tmp.x)
{
	st = ft_nextstar(st, piece);
	tmp = st;
	//				dprintf(2, "\n\n\n<NEXTy %d>    <NEXTx %d>\n\n\n", tmp.y, tmp.x);
	//				x = ft_checkx(map, piece, x); //check if you should go to next x or nah
	x = ft_firstx(map);
	tmpx = x;
}
//			dprintf(2, "\n\n\n<mapy   %d>    <mapy   %d>\n\n\n", x.y, x.x);
//			dprintf(2, "\n\n\n<piecey %d>    <piecex %d>\n\n\n", tmp.y, tmp.x);
//			tmpx.x--;
//			tmp.x--;
}
tmpx.y--;
tmp.y--;
cnt++;
}
dprintf(2, "\n\n\n<mapy   %d>    <mapy   %d>\n\n\n", x.y, x.x);
ft_placex(st, x);
}

void	ft_placex(t_arrcount pi, t_arrcount x)
{
	//		dprintf(2, "\n\n\n<%d><%d>\n\n\n", x.y, x.x);
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
	//	 dprintf(2, "\n\n\n<%d><%d>\n\n\n", x.y, x.x);
	dprintf(1, "%d %d\n", x.y, x.x);
	ft_putnbr(x.y);
	ft_putchar(' ');
	ft_putnbr(x.x);
	ft_putchar('\n');
}*/
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
	//	ret = get_next_line(0, &line);
	while (j < max - 0 && ret)
	{
		ret = get_next_line(0, &line);
		//		dprintf(2, "\n\n<<j%d        ret%d         max%d>>\n\n", j, ret, max);
		//		dprintf(2, "\n\n\n<<7>>\n\n\n");
		piece[j] = line;
		j++;
		//		dprintf(2, "\n\n----->>>>>>>>%s\n\n", line);
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
	dprintf(2, "\n\n\n<<< MAP: >>>\n\n\n");
	ft_putarr(map.arr);
	dprintf(2, "\n\n\nEND\n\n\n");
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
		if (ft_strnequ(line, "Piece", 5))
		{
			piece = ft_piecesize(line);
			dprintf(2, "\n\n\n<<<1>>>------------------------------------\n\n\n");
			map.arr = ft_replace(map.arr, letter);
			dprintf(2, "\n\n\n<<<2>>>------------------------------------\n\n\n");
			ft_place(map, piece);
			dprintf(2, "\n\n\n<<<3>>>------------------------------------\n\n\n");
			dprintf(2, "\n\n\n<<<FT_PLACE>>>\n\n\n");
		}
		ret = get_next_line(0, &line);
	}
	return (0);
}
