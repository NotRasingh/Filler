/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:02:46 by rasingh           #+#    #+#             */
/*   Updated: 2018/08/13 14:33:30 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	l = ft_strlen((char*)needle);
	if (!haystack)
		return (NULL);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && j < l)
	{
		j = 0;
		k = i;
		while (needle[j] == haystack[k] && needle[j])
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
