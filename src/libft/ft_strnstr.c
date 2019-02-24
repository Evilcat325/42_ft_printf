/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 01:06:10 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 19:02:30 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	searched;

	searched = 0;
	while (haystack[searched] && searched < len)
	{
		i = 0;
		while (haystack[searched + i] && needle[i] && searched + i < len
				&& haystack[searched + i] == needle[i])
			i++;
		if (needle[i] == 0)
			return ((char *)haystack + searched);
		searched++;
	}
	return (NULL);
}
