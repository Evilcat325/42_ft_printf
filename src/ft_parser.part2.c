/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:34:24 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/25 21:36:15 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parse_length(char **str, t_fmt *fmt)
{
	if (fmt->length = ft_is_length(*str))
		(*str)++;
	if (ft_is_two_chars_length(*str))
		fmt->length = ft_is_two_chars_length((*str)++);
}

void	ft_parse_specifiers(char **str, t_fmt *fmt)
{
	if (ft_is_specifiers(*str))
		fmt->specifier = *(*str)++;
	else
		fmt->err = ERR_INVALID_SPECIFIER;
	if (!(fmt->specifier & LOWWER))
	{
		fmt->flags.is_uppercase = TRUE;
		fmt->specifier |= LOWWER;
	}
}

void	ft_parse(char **str, t_fmt *fmt)
{
	ft_parse_flags(str, &fmt->flags);
	ft_parse_width(str, fmt);
	ft_parse_precision(str,fmt);
	ft_parse_length(str, fmt);
	ft_parse_specifiers(str, fmt);
}
