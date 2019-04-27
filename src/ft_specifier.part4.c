/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.part4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:12:24 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/27 03:13:12 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"

static int	ft_get_exponent(long double d, long double *dst)
{
	int e;
	e = 0;
	while (d >= 10 && (d /= 10))
		e++;
	while (d < 1 && (d *= 10))
		e--;
	if (dst)
		*dst = d;
	return (e);
}

char		*ft_spec_f(t_state_t *s)
{
	char	*result;

	result = ft_dtoa(s->fmt.input.f, s->fmt.percision);
	if ((int) ft_strlen(result) < s->fmt.width)
		result = ft_pad_wid(s, result);
	return (result);
}

char		*ft_spec_e(t_state_t *s)
{
	char		*result;
	long double	d;
	int			e;

	e = ft_get_exponent(s->fmt.input.f, &d);
	result = ft_dtoa(d, s->fmt.percision);
	result = ft_strjoin_free(result, ft_format_sci(e), TRUE, TRUE);
	if ((int) ft_strlen(result) < s->fmt.width)
		result = ft_pad_wid(s, result);
	return (result);
}

char		*ft_spec_g(t_state_t *s)
{
	char		*result_f;
	char		*result_e;
	long double d;
	int	 		e;

	d = s->fmt.input.f;
	e = ft_get_exponent(s->fmt.input.f, &d);
	s->fmt.percision -= e + 1;
	result_f = ft_spec_f(s);
	result_e = ft_spec_e(s);
	if ((int) ft_strlen(result_f) <= ft_strlen(result_e))
	{
		free(result_e);
		return (result_f);
	}
	else
	{
		 free(result_f);
		 return (result_e);
	}
}

char		*ft_spec_a(t_state_t *s)
{
	return (NULL);
}
