/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.part6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:16:37 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 03:17:54 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"

char					*ft_spec_d(t_state_t *s)
{
	char	*result;

	if(s->fmt.flags.is_left_justify && s->fmt.flags.is_left_pad_zero)
		s->fmt.flags.is_left_pad_zero = FALSE;
	result = (s->fmt.input.i == 0 && s->fmt.percision == 0) ?
		ft_strdup("") : ft_itoa_max(s->fmt.input.i);
	if ((int) ft_strlen(result) < s->fmt.percision)
		result = ft_pad_precision(s, result);
	if ((int) ft_strlen(result) < s->fmt.width)
		result =  s->fmt.flags.is_left_pad_zero ?
			ft_pad_then_sign(s, result) : ft_sign_then_pad(s, result);
	else
		result = ft_add_sign(s, result);
	return result;
}

static t_formatter_t	g_table[] = {
	ft_spec_a, ft_spec_b, ft_spec_c, ft_spec_d,
	ft_spec_e, ft_spec_f, ft_spec_g, ft_spec_err,
	ft_spec_i, ft_spec_err, ft_spec_err, ft_spec_err,
	ft_spec_err, ft_spec_n, ft_spec_o, ft_spec_p,
	ft_spec_err, ft_spec_err, ft_spec_s, ft_spec_err,
	ft_spec_u, ft_spec_err, ft_spec_err, ft_spec_x,
	ft_spec_err, ft_spec_z
};

t_formatter_t			ft_get_formatter(char c)
{
	if ('a' <= c && c <= 'z')
		return g_table[c - 'a'];
	else
		return ft_spec_err;
}

