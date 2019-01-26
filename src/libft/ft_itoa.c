/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 03:05:47 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 19:45:50 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	nbr;
	long	d;
	size_t	i;
	char	*str;

	nbr = n < 0 ? -(long)n : n;
	d = 1;
	i = 1;
	while (nbr / d >= 10)
	{
		d *= 10;
		i++;
	}
	str = ft_strnew(i + (n < 0 ? 1 : 0));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	while (d != 0)
	{
		str[i++] = nbr / d % 10 + '0';
		d /= 10;
	}
	return (str);
}
