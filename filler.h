/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:57:14 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/14 14:05:03 by rasingh          ###   ########.fr       */
/*   Updated: 2018/08/09 14:00:19 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"

typedef struct	s_map
{
	int	x;
	int	y;
	char **arr;
}				t_map;

typedef struct	s_arrcount
{
	int	x;
	int	y;
}				t_arrcount;

#endif
