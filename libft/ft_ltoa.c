/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:47:10 by seli              #+#    #+#             */
/*   Updated: 2019/04/26 01:34:46 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(intmax_t n)
{
	intmax_t	d;
	size_t		i;
	char		*str;

	d = 1;
	i = 1;
	while (ft_abs(n / 10) >= d)
	{
		d *= 10;
		i++;
	}
	if (!(str = ft_strnew(i + (n < 0 ? 1 : 0))))
		return (NULL);
	i = 0;
	if (n < 0)
		str[i++] = '-';
	while (d != 0)
	{
		str[i++] = ft_abs((n / d) % 10) + '0';
		d /= 10;
	}
	return (str);
}
