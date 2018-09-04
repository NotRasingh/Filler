/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:31:03 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/22 12:17:45 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_play(void)
{
	char	*line;

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
