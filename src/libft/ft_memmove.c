/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 23:37:42 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 18:04:15 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst < src)
	{
		i = 0;
		while ((size_t)i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
	}
	return (dst);
}
