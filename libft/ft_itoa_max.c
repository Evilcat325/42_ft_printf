/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:18:04 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 03:47:26 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_max(intmax_t n)
{
	intmax_t	nbr;
	intmax_t	d;
	size_t		i;
	char		*str;
	int			overflow;

	overflow = n == INTMAX_MIN ? 1 : 0;
	n = n == INTMAX_MIN ? n + 1 : n;
	nbr = n < 0 ? -(intmax_t)n : n;
	d = 1;
	i = 1;
	while (nbr / d >= 10 && (d *= 10))
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (d != 0)
	{
		str[i++] = ((nbr / d) % 10) + '0' + (d == 1 ? overflow : 0);
		d /= 10;
	}
	return (str);
}
