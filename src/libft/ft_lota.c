/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:47:10 by seli              #+#    #+#             */
/*   Updated: 2019/01/28 15:27:59 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long long n)
{
	long long	d;
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
