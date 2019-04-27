/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.part5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:13:41 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/27 03:44:06 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"

char	*ft_spec_c(t_state_t *s)
{
	char *result;

	if (s->fmt.width > 1)
	{
		result = ft_pad_wid_char(s, (char)s->fmt.input.i);
		s->fmt.len = s->fmt.width;
	}
	else
	{
		result = ft_strnew(1);
		result[0] = (char)s->fmt.input.i;
		s->fmt.len = 1;
	}
	return (result);
}

char	*ft_spec_s(t_state_t *s)
{
	char	*result;
	size_t	len;

	if (s->fmt.input.p == NULL)
		s->fmt.input.p = "(null)";
	if ((len = ft_strlen(s->fmt.input.p)) && s->fmt.percision >= 0)
		len = len >= s->fmt.percision ? s->fmt.percision : len;
	result = ft_strncpy(ft_strnew(len), s->fmt.input.p, len);
	if (ft_strlen(result) < s->fmt.width)
		result = ft_pad_wid(s, result);
	return (result);
}

char	*ft_spec_p(t_state_t *s)
{
	s->fmt.flags.is_force_alt = TRUE;
	return (ft_spec_x(s));
}

char	*ft_spec_n(t_state_t *s)
{
	s->fmt.input.u = s->len;
	return (ft_spec_d(s));
}

char	*ft_spec_z(t_state_t *s)
{
	s->fmt.input.i = '%';
	return (ft_spec_c(s));
}
