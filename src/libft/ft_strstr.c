/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 00:56:35 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 18:56:01 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*head;
	int		i;

	head = (char *)haystack;
	if (needle[0] == 0)
		return (head);
	while (*head)
	{
		i = 0;
		while (head[i] && needle[i] && head[i] == needle[i])
			i++;
		if (needle[i] == 0)
			return (head);
		head++;
	}
	return (NULL);
}
