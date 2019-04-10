/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 02:46:07 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 19:32:58 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	trim;
	size_t	start;
	size_t	len;
	char	*head;

	if (!s)
		return (NULL);
	trim = 0;
	head = (char *)s;
	while (*head == ' ' || *head == '\n' || *head == '\t')
	{
		head++;
		trim++;
	}
	len = ft_strlen(s);
	start = trim;
	if (trim == len)
		return (ft_strnew(0));
	head = (char *)s + ft_strlen(s) - 1;
	while (*head == ' ' || *head == '\n' || *head == '\t')
	{
		head--;
		trim++;
	}
	return (ft_strsub(s, start, len - trim));
}
