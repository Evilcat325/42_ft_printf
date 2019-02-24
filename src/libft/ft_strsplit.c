/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 02:52:02 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 19:48:03 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**head;
	int				p;
	unsigned int	i;
	size_t			len;

	if (!s)
		return (NULL);
	if (!(head = (char **)malloc(sizeof(s) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = 0;
	p = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		head[p++] = ft_strsub(s, i, len);
		i += len;
	}
	head[p] = 0;
	return (head);
}
