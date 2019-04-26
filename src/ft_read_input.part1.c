/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.part1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 23:31:18 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 00:16:40 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read_input.h"

int	ft_input_signed(t_state_t *s)
{
	if (s->fmt.length == NONE)
		s->fmt.input.i = va_arg(*s->args, int);
	else if (s->fmt.length == hh)
		s->fmt.input.i = (signed char) va_arg(*s->args, int);
	else if (s->fmt.length == h)
		s->fmt.input.i = (short int) va_arg(*s->args, int);
	else if (s->fmt.length == l)
		s->fmt.input.i = va_arg(*s->args, long int);
	else if (s->fmt.length == ll)
		s->fmt.input.i = va_arg(*s->args, long long int);
	else if (s->fmt.length == j)
		s->fmt.input.i = va_arg(*s->args, intmax_t);
	else if (s->fmt.length == z)
		s->fmt.input.i = va_arg(*s->args, size_t);
	else if (s->fmt.length == t)
		s->fmt.input.i = va_arg(*s->args, ptrdiff_t);
	else
		return FALSE;
	return TRUE;
}

int ft_input_unsigned(t_state_t *s)
{
	if (s->fmt.length == NONE)
		s->fmt.input.u = va_arg(*s->args, unsigned int);
	else if (s->fmt.length == hh)
		s->fmt.input.u = (unsigned char) va_arg(*s->args, unsigned int);
	else if (s->fmt.length == h)
		s->fmt.input.u = (unsigned short) va_arg(*s->args, unsigned int);
	else if (s->fmt.length == l)
		s->fmt.input.u = va_arg(*s->args, unsigned long int);
	else if (s->fmt.length == ll)
		s->fmt.input.u = va_arg(*s->args, unsigned long long int);
	else if (s->fmt.length == j)
		s->fmt.input.u = va_arg(*s->args, uintmax_t);
	else if (s->fmt.length == z)
		s->fmt.input.u = va_arg(*s->args, size_t);
	else if (s->fmt.length == t)
		s->fmt.input.u = va_arg(*s->args, ptrdiff_t);
	else
		return FALSE;
	return TRUE;
}

int	ft_input_float(t_state_t *s)
{
	if (s->fmt.length == NONE)
		s->fmt.input.f = va_arg(*s->args, double);
	else if (s->fmt.length == L)
		s->fmt.input.f = va_arg(*s->args, long double);
	else
		return FALSE;
	return TRUE;
}

int	ft_input_c(t_state_t *s)
{
	if (s->fmt.length == NONE)
		s->fmt.input.i = va_arg(*s->args, int);
	else if (s->fmt.length == l)
		s->fmt.input.i = va_arg(*s->args, wint_t);
	else
		return FALSE;
	return TRUE;
}

int	ft_input_s(t_state_t *s)
{
	if (s->fmt.length == NONE)
		s->fmt.input.p = va_arg(*s->args, char *);
	else if (s->fmt.length == l)
		s->fmt.input.p = va_arg(*s->args, wchar_t *);
	else
		return FALSE;
	return TRUE;
}


