/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:30:44 by rasingh           #+#    #+#             */
/*   Updated: 2018/07/10 11:08:58 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = NULL;
	if (s)
	{
		sub = ft_strnew(len);
		if (sub == NULL)
			return (NULL);
		i = 0;
		while (i < len && s[start])
		{
			sub[i] = s[start];
			start++;
			i++;
		}
	}
	return (sub);
}
