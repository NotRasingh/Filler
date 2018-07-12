/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:32:06 by rasingh           #+#    #+#             */
/*   Updated: 2018/05/31 11:14:31 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	i = 0;
	if (!s || !f)
		return (NULL);
	new = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1));
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = f(i, (char)s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
