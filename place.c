/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:23:21 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/17 11:22:34 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print(t_moves *place)
{
	ft_putnbr(place->row);
	ft_putchar(' ');
	ft_putnbr(place->col);
	ft_putchar('\n');
}

void	ft_none(void)
{
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar('\n');
}

void	ft_place(t_map map, t_map piece)
{
	t_moves	*moves;
	t_moves	*place;

	moves = ft_make_list(map, piece);
	if (moves == NULL)
	{
		ft_none();
		return ;
	}
	ft_rate(moves, map);
	place = ft_best(moves);
	ft_print(place);
}

t_moves	*ft_best(t_moves *moves)
{
	t_moves		*tmp;
	t_moves		*best;
	int			rating;

	tmp = moves;
	best = tmp;
	rating = 2147483647;
	while (tmp)
	{
		if (tmp->rating < rating)
		{
			best = tmp;
			tmp->rating = rating;
		}
		tmp = tmp->next;
	}
	return (best);
}
