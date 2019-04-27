/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:34:24 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 17:43:33 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parse_length(t_state_t *s)
{
	if ((s->fmt.length = ft_is_length(*s->curr)))
		s->curr++;
	if (ft_is_two_chars_length(*s->curr))
		s->fmt.length = ft_is_two_chars_length(*s->curr);
}

void	ft_parse_specifiers(t_state_t *s)
{
	if (ft_is_specifiers(*s->curr))
		s->fmt.specifier = *s->curr++;
	else
		s->fmt.err = ERR_INVALID_SPECIFIER;
	if (!(s->fmt.specifier & LOWWER))
	{
		s->fmt.flags.is_uppercase = TRUE;
		s->fmt.specifier |= LOWWER;
	}
	if (s->fmt.specifier == '%')
		s->fmt.specifier = 'z';
}

void	ft_check_invalid_length_specifiers(t_state_t *s)
{
	if ((ft_is_int_specifier(s->fmt.specifier)
			|| ft_is_other_specifier(s->fmt.specifier) == 'n')
		&& s->fmt.length == L)
		s->fmt.err = ERR_INVALID_SPECIFIER_LENGTH;
	else if (ft_is_float_specifier(s->fmt.specifier)
		&& !(s->fmt.length == NONE || s->fmt.length == L))
		s->fmt.err = ERR_INVALID_SPECIFIER_LENGTH;
	else if (ft_is_string_specifier(s->fmt.specifier)
		&& !(s->fmt.length == NONE || s->fmt.length == L))
		s->fmt.err = ERR_INVALID_SPECIFIER_LENGTH;
	else if (s->fmt.specifier == 'p' && s->fmt.length != NONE)
		s->fmt.err = ERR_INVALID_SPECIFIER_LENGTH;
}

void	ft_parse(t_state_t *s)
{
	ft_parse_flags(s);
	ft_parse_width(s);
	ft_parse_precision(s);
	ft_parse_length(s);
	ft_parse_specifiers(s);
	ft_check_invalid_length_specifiers(s);
}
