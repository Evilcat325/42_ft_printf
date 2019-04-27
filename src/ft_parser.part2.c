/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:17:21 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 03:17:23 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parse_length(t_state_t *s)
{
	if ((s->fmt.length = ft_is_length(*s->curr)))
		s->curr++;
	if (ft_is_two_chars_length(*s->curr))
		s->fmt.length = ft_is_two_chars_length(*s->curr++);
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
	if (s->fmt.specifier == 'u' && s->fmt.flags.is_uppercase)
		s->fmt.length = l;
}

void	ft_parse(t_state_t *s)
{
	ft_parse_flags(s);
	ft_parse_width(s);
	ft_parse_precision(s);
	ft_parse_length(s);
	ft_parse_specifiers(s);
}
