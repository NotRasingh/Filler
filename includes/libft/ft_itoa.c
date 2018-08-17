/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:22:39 by rasingh           #+#    #+#             */
/*   Updated: 2018/07/12 09:13:43 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		d;

	d = 0;
	len = ft_intlen(n);
	if (!(num = ft_strnew(len)))
		return (NULL);
	len--;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		num[0] = '-';
		n *= -1;
		d = 1;
	}
	while (len >= d)
	{
		num[len--] = (n % 10) + 48;
		n /= 10;
	}
	num[ft_strlen(num)] = '\0';
	return (num);
}
