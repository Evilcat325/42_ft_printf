/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:10:07 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/27 03:11:02 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"

char	*ft_pad_wid(t_state_t *s, char *str)
{
	char	*result;
	char	fill;
	size_t	len;

	result = ft_strnew(s->fmt.width);
	fill = s->fmt.flags.is_left_pad_zero ? '0': ' ';
	len = s->fmt.width;
	while (len--)
		result[len] = fill;
	len = ft_strlen(str);
	ft_strncpy(s->fmt.flags.is_left_justify ?
		result : (result + s->fmt.width - len), str, len);
	free(str);
	return result;
}

char	*ft_pad_precision(t_state_t *s, char *str)
{
	char	*result;
	size_t	len;

	result = ft_strnew(s->fmt.percision);
	len = s->fmt.percision;
	while (len--)
		result[len] = '0';
	len = ft_strlen(str);
	ft_strncpy(result + s->fmt.percision - len, str, len);
	free(str);
	s->fmt.flags.is_left_pad_zero = FALSE;
	return result;
}

char	*ft_pad_wid_char(t_state_t *s, char c)
{
	char	*result;
	size_t	len;

	result = ft_strnew(s->fmt.width);
	len = s->fmt.width;
	while (len--)
		result[len] = ' ';
	result[s->fmt.flags.is_left_justify ?
		0 : (0 + s->fmt.width - 1)] = c;
	return result;
}
