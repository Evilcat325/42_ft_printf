/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 02:39:16 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 02:43:18 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(intmax_t n)
{
	intmax_t	nbr;
	intmax_t	d;
	size_t		i;
	char		*str;

	nbr = n < 0 ? -(intmax_t)n : n;
	d = 1;
	i = 1;
	while (nbr / d >= 10 && (d *= 10))
		i++;
	if (!(str = ft_strnew(i + (n < 0 ? 1 : 0))))
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
