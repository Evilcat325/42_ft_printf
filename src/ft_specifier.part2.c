/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:11:08 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/27 03:43:28 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"

char	*ft_add_sign(t_state_t *s, char *str)
{
	char *result;

	result = str;
	if (s->fmt.input.i < 0)
		result = ft_strjoin_free("-", result, FALSE, TRUE);
	else if ((s->fmt.flags.is_force_sign || s->fmt.flags.is_force_space))
		result = ft_strjoin_free(s->fmt.flags.is_force_sign ? "+" : " ",
			result, FALSE, TRUE);
	return (result);
}

char	*ft_sign_then_pad(t_state_t *s, char *str)
{
	char *result;

	result = ft_add_sign(s, str);
	result = ft_pad_wid(s, result);
	return (result);
}

char	*ft_pad_then_sign(t_state_t *s, char *str)
{
	char *result;

	result = ft_pad_wid(s, str);
	if (s->fmt.input.i < 0)
		result[0] = '-';
	else if ((s->fmt.flags.is_force_sign || s->fmt.flags.is_force_space))
		result[0] = s->fmt.flags.is_force_sign ? '+' : ' ';
	return (result);
}
