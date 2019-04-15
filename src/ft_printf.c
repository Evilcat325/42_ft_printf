/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:44:15 by seli              #+#    #+#             */
/*   Updated: 2019/04/15 01:10:40 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_length_specifiers(t_fmt *fmt)
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

char	*ft_fmt_double(t_fmt *fmt, long double n)
{
	char		*result;

	result = ft_dtoa(n, fmt->percision);
	if (fmt->flags & FLAG_PLUS_SIGN && (long)n > 0)
		result = ft_strjoin_free("+", result, FALSE, TRUE);
	else if (fmt->flags & FLAG_SPACE && (long)n > 0)
		result = ft_strjoin_free(" ", result, FALSE, TRUE);
	return (result);
}

char	*ft_fmt_int(t_fmt *fmt, long long n)
{
	char		*result;
	long long	nbr;

	nbr = fmt->length ? n & fmt->length : n;
	if (fmt->specifier == 'd' || fmt->specifier == 'i')
	{
		result = ft_ltoa(nbr);
		if (fmt->flags & (FLAG_PLUS_SIGN | FLAG_SPACE) && (long)n > 0)
			result = ft_strjoin_free((
				fmt->flags & FLAG_PLUS_SIGN ? "+" : " "), result, FALSE, TRUE);
	}
	else if (fmt->specifier == 'o')
		result = ft_ltoa_base(nbr, 8);
	else if (fmt->specifier == 'u')
		result = ft_ltoa_base(nbr, 10);
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		result = ft_ltoa_base(nbr, 16);
	else if (fmt->specifier == 'b' || fmt->specifier == 'B')
		result = ft_ltoa_base(nbr, 2);
	if (fmt->specifier == 'c')
	{
		result = ft_strnew(1);
		result[0] = (char)n;
	}
	return (result);
}

char	*ft_fmt_ptr(t_fmt *fmt, void *ptr)
{
	char	*result;

	if (fmt->specifier == 's')
		result = ft_strdup((char *)ptr);
	else if (fmt->specifier == 'p')
		result = ft_strjoin_free("0x",
			ft_ltoa_base((unsigned long long)ptr, 16), FALSE, TRUE);
	return (result);
	}

char	*ft_fmt_width(t_fmt *fmt, char *str)
{
	char *result;
	char *padding;
	int len;

	len = ft_strlen(str);
	if (fmt->width <= len)
		return str;
	padding = ft_strnew(fmt->width - len);
	while (fmt->width - len--)
		padding[fmt->width - len] = fmt->flags & FLAG_ZERO ? '0' : ' ';
	if (fmt->flags & FLAG_NEGATIVE_SIGN)
		result = ft_strjoin_free(str, padding, TRUE, TRUE);
	else
		result = ft_strjoin_free(padding, str, TRUE, TRUE);
	return result;
}

char	*ft_fmt2str(char **str, t_fmt *fmt, va_list args)
{
	char	*result;

	(*str)++;
	ft_read_flags(str, fmt);
	ft_read_width(str, fmt, args);
	ft_read_precision(str, fmt, args);
	ft_read_length(str, fmt);
	ft_read_specifiers(str, fmt);
	if (!fmt->err && fmt->length)
		ft_check_length_specifiers(fmt);
	if (fmt->err)
		return (NULL);
	if (ft_strchr(DOUBLE_SPECIFIER, fmt->specifier))
		result = ft_fmt_double(fmt, va_arg(args, long double));
	else if (ft_strchr(INT_SPECIFIER, fmt->specifier))
		result = ft_fmt_int(fmt, va_arg(args, long long));
	else if (ft_strchr(PTR_SPECIFIER, fmt->specifier))
		result = ft_fmt_ptr(fmt, va_arg(args, void *));
	else if (fmt->specifier == '%')
	{
		result = ft_strnew(1);
		result[0] = '%';
	}
	result = ft_fmt_width(fmt, result);
	return (result);
}

void	ft_dprintf(int fd, const char *str, va_list args)
{
	char	*head;
	t_fmt	fmt;
	char	*result;

	if (!str)
		return ;
	head = (char *)str;
	while (*head)
	{
		ft_putstr_fd_end(fd, &head, '%');
		if (!*head)
			break;
		ft_bzero(&fmt, sizeof(fmt));
		if ((result = ft_fmt2str(&head, &fmt, args)))
		{
			ft_putstr_fd(result, fd);
			free(result);
		}
		else
		{
			ft_putstr_fd("Invalid format\n", fd);
			break ;
		}
	}
	va_end(args);
}

void ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft_dprintf(STDOUT_FILENO, str, args);
}
