/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 00:51:30 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 18:52:04 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*search;

	search = (char *)s;
	while (*search)
	{
		if (*search == (char)c)
			return (search);
		search++;
	}
	return (c == 0 ? search : NULL);
}
