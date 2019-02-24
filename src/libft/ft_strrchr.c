/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 00:54:54 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 18:50:26 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*search;
	char	*last;

	search = (char *)s;
	last = NULL;
	while (*search)
	{
		if (*search == (char)c)
			last = search;
		search++;
	}
	return (c == 0 ? search : last);
}
