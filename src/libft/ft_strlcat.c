/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 00:44:49 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 18:45:03 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (i + dst_len + 1 < dstsize)
	{
		if (src[i] == 0)
			break ;
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return ((dst_len < dstsize ? dst_len : dstsize) + src_len);
}
