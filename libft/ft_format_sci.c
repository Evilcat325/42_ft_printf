/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_sci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 01:58:36 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 02:00:46 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_format_sci(int e)
{
	char *result;

	result = ft_strnew(4);
	result[0] = 'e';
	result[1] = e >= 0 ? '+' : '-';
	e = e >= 0 ? e : - e;
	result[2] = e / 10 + '0';
	result[3] = e % 10 + '0';
	return result;
}
