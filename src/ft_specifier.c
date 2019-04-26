/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:50:19 by seli              #+#    #+#             */
/*   Updated: 2019/04/26 01:30:36 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"
#define ft_spec_i ft_spec_d

char *ft_spec_d(t_state_t *s)
{
	char *result;

	result = ft_itoa_max(s->fmt.input.i);
	return result;
}

char *ft_spec_b(t_state_t *s)
{
	char *result;

	result = ft_ltoa_base(s->fmt.input.u, 2);
	return result;
}

char *ft_spec_o(t_state_t *s);
{
	char *result;

	result = ft_ltoa_base(s->fmt.input.u, 8);
}

char *ft_spec_u(t_state_t *s)
{
	char *result;

	result = ft_ltoa_base(s->fmt.input.u, 10);
	return result;
}

char *ft_spec_x(t_state_t *s)
{
	char *result;

	result = ft_lota_base(s->fmt.input.u, 16);
	return result;
}

char *ft_spec_f(t_state_t *s);
char *ft_spec_e(t_state_t *s);
char *ft_spec_g(t_state_t *s);
char *ft_spec_a(t_state_t *s);

char *ft_spec_c(t_state_t *s)
{
	char *result;

	result = ft_strdup(&s->fmt.input.i);
	return result;
}

char *ft_spec_s(t_state_t *s)
{
	char *result;

	result = ft_strdup(s->fmt.input.p);
	return result;
}

char *ft_spec_p(t_state_t *s)
{
	char *result;

	result = ft_ltoa_base(s->fmt.input.p, 16);
	return result;
}

char *ft_spec_n(t_state_t *s)
{
	char *result;

	result = ft_itoa_max(s->len);
	return result;
}

char *ft_spec_z(t_state_t *s)
{
	char *result;

	result = ft_strdup("%");
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

