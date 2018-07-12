/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:31:36 by rasingh           #+#    #+#             */
/*   Updated: 2018/06/29 13:23:50 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	while (t1[i] == t2[i] && t1[i] != '\0' && t2[i] != '\0' && i < n)
		i++;
	if (i < n)
		return ((int)t1[i] - (int)t2[i]);
	return (0);
}
