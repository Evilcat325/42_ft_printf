/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.part2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 00:16:22 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 00:19:02 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_input.h"

int	ft_input_p(t_state_t *s)
{
	if (s->fmt.length == NONE)
		s->fmt.input.p = va_arg(*s->args, void *);
	else
		return FALSE;
	return TRUE;
}

int	ft_input_n(t_state_t *s)
{
	if (s->fmt.length == NONE)
		s->fmt.input.p = va_arg(*s->args, int *);
	else if (s->fmt.length == hh)
		s->fmt.input.p = va_arg(*s->args, signed char *);
	else if (s->fmt.length == h)
		s->fmt.input.p = va_arg(*s->args, short int *);
	else if (s->fmt.length == l)
		s->fmt.input.p = va_arg(*s->args, long int *);
	else if (s->fmt.length == ll)
		s->fmt.input.p = va_arg(*s->args, long long int *);
	else if (s->fmt.length == j)
		s->fmt.input.p = va_arg(*s->args, intmax_t *);
	else if (s->fmt.length == z)
		s->fmt.input.p = va_arg(*s->args, size_t *);
	else if (s->fmt.length == t)
		s->fmt.input.p = va_arg(*s->args, ptrdiff_t *);
	else
		return FALSE;
	return TRUE;
}

int	ft_input_z(t_state_t *s)
{
	return TRUE;
}

static t_inputter_t	g_table[] = {
	ft_input_float,		ft_input_unsigned,	ft_input_c,			ft_input_signed,
	ft_input_float,		ft_input_float,		ft_input_float,		ft_input_err,
	ft_input_signed,	ft_input_err,		ft_input_err,		ft_input_err,
	ft_input_err,		ft_input_n,			ft_input_unsigned,	ft_input_p,
	ft_input_err,		ft_input_err,		ft_input_s,			ft_input_err,
	ft_input_unsigned,	ft_input_err,		ft_input_err,		ft_input_unsigned,
	ft_input_err,		ft_input_z
};

t_inputter_t	ft_get_inputter(char c)
{
	if ('a' <= c && c <= 'z')
		return g_table[c - 'a'];
	else
		return NULL;
}
