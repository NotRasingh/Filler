/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:22:08 by rasingh           #+#    #+#             */
/*   Updated: 2018/06/07 09:31:06 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
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
		new[i] = f((char)s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
