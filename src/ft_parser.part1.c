/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:55:34 by seli              #+#    #+#             */
/*   Updated: 2019/04/25 21:38:08 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parse_flags(char **str, t_flags *flags)
{
	while (ft_is_flag(*str))
	{
		if (*str == '-')
			flags->is_force_sign= TRUE;
		else if (*str == '+')
			flags->is_force_sign = TRUE;
		else if (*str == ' ')
			flags->is_force_space = TRUE;
		else if (*str == '#')
			flags->is_force_alt = TRUE;
		else if (*str == '0')
			flags->is_left_pad_zero = TRUE;
		(*str)++;
	}
}

static void	ft_parse_number(char **str, t_fmt *fmt, int *dst)
{
	if (**str == '*')
	{
		*dst = va_arg(*(fmt->args), int);
		(*str)++;
	} else if (!ft_isdigit(**str))
		return ;
	else
		while (ft_isdigit(**str))
			*dst = *dst * 10 + *(*str)++ - '0';
}

void	ft_parse_width(char **str, t_fmt *fmt)
{
	ft_parse_number(str, fmt, &fmt->width);
}

void	ft_parse_precision(char **str, t_fmt *fmt)
{
	fmt->percision = -1;
	if (*(*str)++ != '.')
		return;
	ft_parse_number(str, fmt, &fmt->percision);
}

