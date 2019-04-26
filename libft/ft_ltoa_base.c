/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 03:32:31 by seli              #+#    #+#             */
/*   Updated: 2019/04/26 01:34:00 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(uintmax_t n, int base)
{
	uintmax_t			d;
	size_t				i;
	char				*str;
	char				c;

	d = 1;
	i = 1;
	while (n / base >= d)
	{
		d *= base;
		i++;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (d != 0)
	{
		c = (n / d) % base;
		c = c >= 10 ? c - 10 + 'a' : c + '0';
		str[i++] = c;
		d /= base;
	}
	return (str);
}
