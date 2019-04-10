/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:55:34 by seli              #+#    #+#             */
/*   Updated: 2019/03/02 01:02:20 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_read_flags(char **str, t_fmt *fmt)
{
	while (ft_strchr("+- #0", **str))
	{
		fmt->flags |= (**str == '-' ? FLAG_NEGATIVE_SIGN : 0);
		fmt->flags |= (**str == '+' ? FLAG_PLUS_SIGN : 0);
		fmt->flags |= (**str == ' ' ? FLAG_SPACE : 0);
		fmt->flags |= (**str == '#' ? FLAG_HASHTAG : 0);
		fmt->flags |= (**str == '0' ? FLAG_ZERO : 0);
		fmt->flags |= (**str == '\'' ? FLAG_AOISTRIOHE : 0);
		(*str)++;
	}
}

void	ft_read_width(char **str, t_fmt *fmt, va_list arg)
{
	fmt->width = -1;
	if (**str == '*')
		fmt->width = va_arg(arg, int);
	else if (ft_isdigit(**str))
		fmt->width = ft_atoi(*str);
	while (ft_isdigit(**str) || **str == '*')
		(*str)++;
}

void	ft_read_precision(char **str, t_fmt *fmt, va_list arg)
{
	fmt->percision = -1;
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
			fmt->percision = va_arg(arg, int);
		else if (ft_isdigit(**str))
			fmt->percision = ft_atoi(*str);
		while (ft_isdigit(**str) || **str == '*')
			(*str)++;
	}
}

void	ft_read_length(char **str, t_fmt *fmt)
{
	if (ft_strchr("hljztL", **str))
	{
		fmt->length = (**str == 'h' ? LENGTH_H : fmt->length);
		fmt->length = (**str == 'l' ? LENGTH_L : fmt->length);
		fmt->length = (**str == 'L' ? LENGTH_LD : fmt->length);
		(*str++);
	}
	if (ft_strchr("hl", **str))
	{
		fmt->length = (**str == 'h' ? LENGTH_HH : fmt->length);
		fmt->length = (**str == 'l' ? LENGTH_LL : fmt->length);
		(*str++);
	}
}

void	ft_read_specifiers(char **str, t_fmt *fmt)
{
	if (ft_strchr(SPECIFIER, **str))
		fmt->specifier = *(*str++);
	else
		fmt->err = ERR_INVALID_SPECIFIER;
}
