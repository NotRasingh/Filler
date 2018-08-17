/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:32:43 by rasingh           #+#    #+#             */
/*   Updated: 2018/07/12 08:15:46 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && j < len)
	{
		k = i;
		while (needle[j] == haystack[k] && k < len && needle[j])
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)&haystack[i]);
		j = 0;
		i++;
	}
	return (0);
}
