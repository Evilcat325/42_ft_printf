/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:48:04 by seli              #+#    #+#             */
/*   Updated: 2019/04/13 14:22:40 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(long double n, int percision)
{
	char		*result;
	long double	fraction;
	int			i;
	char		*dec;

	result = ft_ltoa((long)n);
	percision = percision == -1 ? 6 : percision;
	if (percision != 0)
	{
		result = ft_strjoin_free(result, ".", TRUE, FALSE);
		fraction = n - (long)n;
		i = 0;
		dec = ft_strnew(percision);
		while (i < percision)
		{
			fraction *= 10;
			dec[i] = (long)fraction % 10 + '0';
			fraction -= (long)fraction;
			i++;
		}
		result = ft_strjoin_free(result, dec, TRUE, TRUE);
	}
	return result;
}
