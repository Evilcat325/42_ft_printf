/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 03:32:31 by seli              #+#    #+#             */
/*   Updated: 2019/01/28 15:33:59 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa_base(unsigned long long n, int base)
{
	unsigned long long	d;
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
