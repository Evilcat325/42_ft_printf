/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 02:25:40 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 19:22:03 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dup;
	int		i;

	if (!s || !f)
		return (NULL);
	dup = ft_strnew(ft_strlen(s));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = f(s[i]);
		i++;
	}
	return (dup);
}
