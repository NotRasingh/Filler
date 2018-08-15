/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Newfiller.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:26:24 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/15 16:17:06 by rasingh          ###   ########.fr       */
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

void	ft_add_node(t_moves **head, int row, int col)
{
	t_moves	*tmp;
	t_moves	*node;

	node = malloc(sizeof(t_moves));
	node->row = row;
	node->col = col;
	node->rating = 2147483647;
	if (*head == NULL)
	{
		node->next = NULL;
		*head = node;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		tmp->next = NULL;
	}
	dprintf(2, "---------------------------------Das not good---------------------------\n");
}

int		ft_out_of_bounds(t_map map, t_map piece, int row, int col)
{
	if (row + piece.y > map.y || col + piece.x > map.x)
		return (1);
	return (0);
}
int		ft_isvalid(t_map map, t_map piece, int row, int col)
{
	int	p_r;
	int	p_c;
	int	count;

	count = 0;
	p_r = 0;
	if (ft_out_of_bounds(map, piece, row, col))
	{
		dprintf(2, "---------------------------------<< NOT AGAIN\n %d %d >>---------------------------\n", row + piece.y, col + piece.x);
		return (0);
		}
	while (p_r < piece.y)
	{
		p_c = 0;
		while (p_c < piece.x)
		{
			if (piece.arr[p_r][p_c] == '*' && map.arr[row][col] != '.'
					&& map.arr[row][col] != 'k')
				return (0);
			if (piece.arr[p_r][p_c] == '*' && map.arr[row][col] == 'k')
				count++;
			p_c++;
			col++;
		}
		p_r++;
		row++;
	}
	return(count);
}
void	ft_distance(t_moves *moves, t_map map)
{
	int	row;
	int	col;
	int	rating;

	row = 0;
	while (row < map.y)
	{
		col = 0;
		while (col < map.x)
		{
			if (map.arr[row][col] != 'k' && map.arr[row][col] != '.')
			{
				rating = abs(col - moves->col) + abs(row - moves->row);
				if (rating < moves->rating)
					moves->rating = rating;
			}
			col++;
		}
		row++;
	}
}

t_moves		*ft_best(t_moves *moves)
{
	t_moves		*tmp;
	t_moves		*best;
	int			rating;

	tmp = moves;
	best = tmp;
	rating = 2147483647;
	while (tmp)
	{
		if (tmp->rating > rating)
		{
			best = tmp;
			tmp->rating = rating;
		}
		tmp = tmp->next;
	}
	return (best);
}

void	ft_print(t_moves *place)
{
	ft_putnbr(place->row);
	ft_putchar(' ');
	ft_putnbr(place->col);
	ft_putchar('\n');
}

void	ft_rate(t_moves *moves, t_map map)
{
	t_moves	*tmp;

	tmp = moves;
	while(tmp)
	{
		ft_distance(tmp, map);
		tmp = tmp->next;
	}
}

void	ft_none(void)
{
	 ft_putnbr(0);
    ft_putchar(' ');
    ft_putnbr(0);
    ft_putchar('\n');
}

t_moves     *ft_make_list(t_map piece, t_map map)
 {
     t_moves *head;
     int     row;
     int     col;

     head = NULL;
     row = 0;
     while (row < map.y)
     {
         col = 0;
         while (col < map.x)
         {
             if (ft_isvalid(map, piece, row, col) == 1)
			 {
				 dprintf(2, "---------------------------------gotchu------------------------------------------------------------------------------\n");
				 dprintf(2, "---------------------------------<< %d %d >>---------------------------\n", row, col);
				 ft_add_node(&head, row, col);
			 }
             col++;
         }
		 dprintf(2, "---------------------------------<< %d >>---------------------------\n", row);
         row++;
     }
     return(head);
}

void	ft_place(t_map map, t_map piece)
{
	t_moves *moves;
	t_moves	*place;

	moves = ft_make_list(map, piece);
	dprintf(2, "---------------------------------HOW BOUT NAH---------------------------\n");
	if (moves == NULL)
	{
		ft_none();
		return ;
	}
	dprintf(2, "---------------------------------<< Y U DO DIS >>---------------------------\n");
	ft_rate(moves, map);
	dprintf(2, "---------------------------------Dasnotgood---------------------------\n");
	place = ft_best(moves);
	dprintf(2, "---------------------------------CAN U NOT---------------------------\n");
	ft_print(place);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void	ft_getpiece(char **line, t_map map)
{
	static t_map	piece;
	int				j;

	j = 0;
	if (!piece.arr)
		piece = ft_init(piece, line);
	while (j < piece.y)
	{
		get_next_line(0, line);
		piece.arr[j] = *line;
		j++;
	}
	ft_place(piece, map);
}

void	ft_getmap(char **line)
{
	static t_map	map;
	int				j;

	j = 0;
	if (!map.arr)
		map = ft_init(map, line);
	get_next_line(0, line);
	while (1)
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

int		ft_play(void)
{
	char *line;

	if (get_next_line(0, &line))
	{
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

/*
int		main(void)
{
	t_moves *node5 = malloc(sizeof(t_moves));
	node5->data = blah;
	node5->next = NULL;

	t_moves *node4 = malloc(sizeof(t_moves));
	node4->data = blah;
	node4->next = node5;

	t_moves
}
*/
