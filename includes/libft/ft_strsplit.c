/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:54:09 by rasingh           #+#    #+#             */
/*   Updated: 2018/06/11 13:04:45 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numword(char *s, char c)
{
	int	i;
	int j;

	i = 0;
	if (!s)
		return (0);
	if (*s != c)
		i = 1;
	j = 1;
	while (s[j])
	{
		if (s[j] != c && s[j - 1] == c)
			i++;
		j++;
	}
	return (i);
}

static int	ft_lenword(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j] != c && s[j] != '\0')
	{
		i++;
		j++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	if (!(split = (char**)malloc(sizeof(split) *
					(ft_numword((char*)s, c)) + 1)) || !s)
		return (NULL);
	while (s[k] != '\0')
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		if (s[k] == '\0')
			break ;
		split[i] = (char*)ft_strnew(ft_lenword((char*)&s[k], c));
		j = 0;
		while (s[k] != c && s[k] != '\0')
			split[i][j++] = s[k++];
		split[i][j] = '\0';
		i++;
	}
	split[i] = 0;
	return (split);
}
