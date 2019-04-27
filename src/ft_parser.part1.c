/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:55:34 by seli              #+#    #+#             */
/*   Updated: 2019/04/26 17:42:35 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parse_flags(t_state_t *s)
{
	char c;

	while (ft_is_flag(c = *s->curr) && s->curr++)
		if (c == '-')
			s->fmt.flags.is_force_sign= TRUE;
		else if (c == '+')
			s->fmt.flags.is_force_sign = TRUE;
		else if (c == ' ')
			s->fmt.flags.is_force_space = TRUE;
		else if (c == '#')
			s->fmt.flags.is_force_alt = TRUE;
		else if (c == '0')
			s->fmt.flags.is_left_pad_zero = TRUE;
}

static void	ft_parse_number(t_state_t *s, unsigned int *dst)
{
	if (*s->curr == '*')
	{
		*dst = va_arg(*s->args, unsigned int);
		s->curr++;
	} else if (!ft_isdigit(*s->curr))
		return ;
	else
		while (ft_isdigit(*s->curr))
			*dst = *dst * 10 + *s->curr++ - '0';
}

void	ft_parse_width(t_state_t *s)
{
	ft_parse_number(s, &s->fmt.width);
}

void	ft_parse_precision(t_state_t *s)
{
	s->fmt.percision = -1;
	if (*(s->curr)++ != '.')
		return;
	ft_parse_number(s, &s->fmt.percision);
}

