/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:44:15 by seli              #+#    #+#             */
/*   Updated: 2019/01/26 18:55:25 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include "libft.h"
#include "ft_printf.h"

size_t	ft_strlen_end(char *str, char end)
{
	size_t	len;

	len = 0;
	while (*str && *str != end)
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_putstr_fd_end(int fd, char **str, char end)
{
	size_t	len;

	len = ft_strlen_end(*str, end);
	write(fd, *str, len);
	*str += len;
}

void	ft_read_flags(char **str, t_fmt *fmt)
{
	while (ft_strchr("+- #0", **str))
	{
		fmt->flags |= (**str == '+' ? FLAG_NEGATIVE_SIGN : 0);
		fmt->flags |= (**str == '+' ? FLAG_PLUS_SIGN : 0);
		fmt->flags |= (**str == '+' ? FLAG_SPACE : 0);
		fmt->flags |= (**str == '+' ? FLAG_HASHTAG : 0);
		fmt->flags |= (**str == '+' ? FLAG_ZERO : 0);
		(*str)++;
	}
}

void	ft_read_width(char **str, t_fmt *fmt, va_list arg)
{
	if (**str == '*')
		fmt->width = va_arg(arg, int);
	else if (ft_isdigit(**str))
		fmt->width = ft_atoi(*str);
	while (ft_isdigit(**str) || **str == '*')
		(*str)++;
}

void	ft_read_precision(char **str, t_fmt *fmt, va_list arg)
{
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
		fmt->length = (**str == 'j' ? LENGTH_J : fmt->length);
		fmt->length = (**str == 'z' ? LENGTH_Z : fmt->length);
		fmt->length = (**str == 't' ? LENGTH_T : fmt->length);
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

void		ft_check_length_specifiers(t_fmt *fmt)
{
	if (fmt->length == LENGTH_LD)
	{
		if (!ft_strchr(DOUBLE_SPECIFIER, fmt->specifier))
			fmt->err = ERR_INVALID_LENGTH_WITH_SPECIFIER;
	}
	else if (ft_strchr(DOUBLE_SPECIFIER, fmt->specifier)
		|| fmt->specifier == 'p')
		fmt->err = ERR_INVALID_LENGTH_WITH_SPECIFIER;
	else if ((fmt->specifier == 'c' || fmt->specifier == 's')
		&& fmt->length != LENGTH_L)
		fmt->err = ERR_INVALID_LENGTH_WITH_SPECIFIER;
}

void	ft_print_fmt(t_fmt *fmt, va_list args)
{
}

int		ft_parse_fmt(char **str, t_fmt *fmt, va_list args)
{
	ft_read_flags(str, fmt);
	ft_read_width(str, fmt, args);
	ft_read_precision(str, fmt, args);
	ft_read_length(str, fmt);
	ft_read_specifiers(str, fmt);
	if (!fmt->err && fmt->length)
		ft_check_length_specifiers(fmt);
	if (fmt->err)
		return (FALSE);
	if (ft_strchr(DOUBLE_SPECIFIER, fmt->specifier))
		ft_print_double(fmt, va_arg(args, long double));
	else if (ft_strchr(INT_SPECIFIER, fmt->specifier))
		ft_print_int(fmt, va_arg(args, uintmax_t));
	else if (ft_strchr(PTR_SPECIFIER, fmt->specifier))
		ft_print_ptr(fmt, va_arg(args, void *));
	return (TRUE);
}

void	ft_dprintf(int fd, const char *str, ...)
{
	char			*head;
	t_fmt			fmt;
	va_list			args;

	if (!str)
		return ;
	va_start(args, str);
	head = (char *)str;
	while (*head)
	{
		ft_bzero(&fmt, sizeof(fmt));
		ft_putstr_fd_end(fd, &head, '%');
		if (!ft_parse_fmt(&head, &fmt, args))
		{
			ft_putstr_fd("Invalid format\n", fd);
			break ;
		}
	}
	va_end(args);
}
