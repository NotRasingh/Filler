/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:26:55 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/17 11:12:21 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		ft_add_node(t_moves **head, int row, int col)
{
	t_moves *tmp;
	t_moves *node;

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
}

int			ft_isvalid(t_map map, t_map piece, int row, int col)
{
	int p_r;
	int p_c;
	int count;

	count = 0;
	p_r = 0;
	while (p_r < piece.y)
	{
		p_c = 0;
		while (p_c < piece.x)
		{
			if (piece.arr[p_r][p_c] == '*'
					&& map.arr[row + p_r][col + p_c] != '.'
					&& map.arr[row + p_r][col + p_c] != 'k')
				return (0);
			if (piece.arr[p_r][p_c] == '*'
					&& map.arr[row + p_r][col + p_c] == 'k')
				count++;
			p_c++;
		}
		p_r++;
	}
	return (count);
}

void		ft_distance(t_moves *moves, t_map map)
{
	int row;
	int col;
	int rating;

	row = 0;
	while (row < map.y)
	{
		col = 0;
		while (col < map.x)
		{
			if (map.arr[row][col] != 'k' && map.arr[row][col] != '.')
			{
				rating = ((col - moves->col) * (col - moves->col))
					+ ((row - moves->row) * (row - moves->row));
				if (rating < moves->rating)
					moves->rating = rating;
			}
			col++;
		}
		row++;
	}
}

void		ft_rate(t_moves *moves, t_map map)
{
	t_moves *tmp;

	tmp = moves;
	while (tmp)
	{
		ft_distance(tmp, map);
		tmp = tmp->next;
	}
}

t_moves		*ft_make_list(t_map map, t_map piece)
{
	t_moves	*head;
	int		row;
	int		col;

	head = NULL;
	row = 0;
	while (row <= map.y - piece.y)
	{
		col = 0;
		while (col <= map.x - piece.x)
		{
			if (ft_isvalid(map, piece, row, col) == 1)
			{
				ft_add_node(&head, row, col);
			}
			col++;
		}
		row++;
	}
	return (head);
}
