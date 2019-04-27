/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:50:19 by seli              #+#    #+#             */
/*   Updated: 2019/04/26 03:09: by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"
#define ft_spec_i ft_spec_d

char *ft_pad_left_zero(t_state_t *s, char *str)
{
	size_t	len;
	char	*result;
	char	*head;

	len = ft_strlen(str);
	head = result = ft_strnew(s->fmt.percision - len);
	while (*head)
		*head = '0';
	return ft_strjoin_free(result, str, TRUE, TRUE);
}

char *ft_pad_wid(t_state_t *s, char *str)
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

char *ft_spec_d(t_state_t *s)
{
	char	*result;

	if (s->fmt.input.i == 0 && s->fmt.percision == 0)
		return ft_strdup("");
	result = ft_itoa_max(s->fmt.input.i);
	if (s->fmt.percision > 0 && ft_strlen(result) < s->fmt.percision)
		result = ft_pad_left_zero(s, result);
	if (s->fmt.input.i >= 0
		&& (s->fmt.flags.is_force_sign || s->fmt.flags.is_force_space))
		result = ft_strjoin_free(s->fmt.flags.is_force_sign ? "+" : " ",
			result, FALSE, TRUE);
	if (ft_strlen(result) < s->fmt.width)
		result = ft_pad_wid(s, result);
	return result;
}

char *ft_spec_unsigned(t_state_t *s, int base, char *alt)
{
	char	*result;

	if (s->fmt.input.i == 0 && s->fmt.percision == 0)
		result = ft_strdup("");
	else
	{
		result = ft_ltoa_base(s->fmt.input.u, base);
		if (s->fmt.percision > 0 && ft_strlen(result) < s->fmt.percision)
			result = ft_pad_left_zero(s, result);
		if (result[0] != '0' && s->fmt.flags.is_force_alt)
			result = ft_strjoin_free(alt, result, FALSE, TRUE);
	}
	if (ft_strlen(result) < s->fmt.width)
		result = ft_pad_wid(s, result);
	return result;
}

char *ft_spec_b(t_state_t *s)
{
	return ft_spec_unsigned(s, 2, "0");
}

char *ft_spec_o(t_state_t *s)
{
	return ft_spec_unsigned(s, 8, "0");
}

char *ft_spec_u(t_state_t *s)
{
	return ft_spec_unsigned(s, 10, "");
}

char *ft_spec_x(t_state_t *s)
{
	char	*result;
	char	*head;

	if(s->fmt.flags.is_left_justify && s->fmt.flags.is_left_pad_zero)
		s->fmt.flags.is_left_pad_zero = FALSE;
	result = ft_spec_unsigned(s, 16, "0x");
	if(s->fmt.flags.is_force_alt && s->fmt.flags.is_left_pad_zero)
	{
		head = result;
		while (*head && *head != 'x')
			head++;
		*head = '0';
		result[1] = 'x';
	}
	return (result);
}

char *ft_spec_f(t_state_t *s)
{
	char	*result;

	result = ft_dtoa(s->fmt.input.f, s->fmt.percision);
	if (ft_strlen(result) < s->fmt.width)
		result = ft_pad_wid(s, result);
	return result;
}

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

char *ft_spec_e(t_state_t *s)
{
	char		*result;
	long double	d;
	int			e;

	e = ft_get_exponent(s->fmt.input.f, &d);
	result = ft_dtoa(d, s->fmt.percision);
	result = ft_strjoin_free(result, ft_format_sci(e), TRUE, TRUE);
	if (ft_strlen(result) < s->fmt.width)
		result = ft_pad_wid(s, result);
	return result;
}

char *ft_spec_g(t_state_t *s)
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
	if (ft_strlen(result_f) <= ft_strlen(result_e))
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

char *ft_spec_a(t_state_t *s)
{
	return NULL;
}

char *ft_spec_c(t_state_t *s)
{
	char *result;

	result = ft_strnew(1);
	result[0] = (char) s->fmt.input.i;
	s->fmt.len = 1;
	if (s->fmt.width > 1)
	{
		result = ft_pad_wid(s, result);
		s->fmt.len = s->fmt.width;
	}
	return result;
}

char *ft_spec_s(t_state_t *s)
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
	return result;
}

char *ft_spec_p(t_state_t *s)
{
	s->fmt.flags.is_force_alt = TRUE;
	return ft_spec_x(s);
}

char *ft_spec_n(t_state_t *s)
{
	s->fmt.input.u = s->len;
	return ft_spec_d(s);
}

char *ft_spec_z(t_state_t *s)
{
	s->fmt.input.i = '%';
	return ft_spec_c(s);
}

static t_formatter_t g_table[] = {
	ft_spec_a,		ft_spec_b,		ft_spec_c,		ft_spec_d,
	ft_spec_e,		ft_spec_f,		ft_spec_g,		ft_spec_err,
	ft_spec_i,		ft_spec_err,	ft_spec_err,	ft_spec_err,
	ft_spec_err,	ft_spec_n,		ft_spec_o,		ft_spec_p,
	ft_spec_err,	ft_spec_err,	ft_spec_s,		ft_spec_err,
	ft_spec_u,		ft_spec_err,	ft_spec_err,	ft_spec_x,
	ft_spec_err,	ft_spec_z
};

t_formatter_t ft_get_formatter(char c)
{
	if ('a' <= c && c <= 'z')
		return g_table[c - 'a'];
	else
		return ft_spec_err;
}

