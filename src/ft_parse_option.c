/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:55:34 by seli              #+#    #+#             */
/*   Updated: 2019/04/15 21:17:55 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

int		ft_is_length(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 't' || c == 'L');
}

int		ft_is_two_chars_length(char c)
{
	return (c == 'h' || c == 'l');
}

int		ft_is_specifiers(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X'
		|| c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == "G"
		|| c == 'a' || c == 'A' || c == 'c' || c == 's' || c == 'p' || c == 'n');
}

void	ft_parse_flags(char **str, t_fmt *fmt)
{
	while (ft_is_flag(*str))
	{
		if (*str == '-')
			fmt->left_justify = TRUE;
		else if (*str == '+')
			fmt->force_sign = TRUE;
		else if (*str == ' ')
			fmt->force_space = TRUE;
		else if (*str == '#')
		{
			fmt->force_zero = TRUE;
			fmt->force_decimal = TRUE;
		} else if (*str == '0')
			fmt->force_zero = TRUE;
		(*str)++;
	}
}

void	ft_parse_width(char **str, t_fmt *fmt)
{
	fmt->width = -1;
	if (**str == '*')
		fmt->width = va_arg(*(fmt->args), int);
	else if (ft_isdigit(**str))
		fmt->width = ft_atoi(*str);
	while (ft_isdigit(**str) || **str == '*')
		(*str)++;
}

void	ft_parse_precision(char **str, t_fmt *fmt)
{
	fmt->percision = -1;
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
			fmt->percision = va_arg(*(fmt->args), int);
		else if (ft_isdigit(**str))
			fmt->percision = ft_atoi(*str);
		while (ft_isdigit(**str) || **str == '*')
			(*str)++;
	}
}

void	ft_parse_length(char **str, t_fmt *fmt)
{
	if (ft_is_length(*str))
		fmt->length = *(*str)++;
	if (ft_is_two_chars_length(*str))
		fmt->length = *(*str)++ + 'A' - 'a';
}

void	ft_parse_specifiers(char **str, t_fmt *fmt)
{
	if (ft_is_specifiers(*str))
		fmt->specifier = *(*str)++;
	else
		fmt->err = ERR_INVALID_SPECIFIER;
}
