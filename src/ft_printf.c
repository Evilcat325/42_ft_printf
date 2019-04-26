/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:44:15 by seli              #+#    #+#             */
/*   Updated: 2019/04/25 21:38:51 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_invalid_length_specifiers(t_fmt *fmt)
{
	if ((ft_is_int_specifier(fmt->specifier) || fmt->specifier == 'n')
		&& fmt->length == 'L')
		fmt->err = ERR_INVALID_SPECIFIER_LENGTH;
	else if (ft_is_double_specifier(fmt->specifier)
		&& !(fmt->length == 'n' || fmt->length == 'L'))
		fmt->err = ERR_INVALID_SPECIFIER_LENGTH;
	else if (ft_is_string_specifier(fmt->specifier)
		&& !(fmt->length == 'n' || fmt->length == 'l'))
		fmt->err == ERR_INVALID_SPECIFIER_LENGTH;
	else if (fmt->specifier == 'p' && fmt->length != 'n')
		fmt->err == ERR_INVALID_SPECIFIER_LENGTH;
}

// char	*ft_fmt_double(t_fmt *fmt, long double n)
// {
// 	char		*result;

// 	result = ft_dtoa(n, fmt->percision);
// 	if (fmt->flags & FLAG_PLUS_SIGN && (long)n > 0)
// 		result = ft_strjoin_free("+", result, FALSE, TRUE);
// 	else if (fmt->flags & FLAG_SPACE && (long)n > 0)
// 		result = ft_strjoin_free(" ", result, FALSE, TRUE);
// 	return (result);
// }

int		map_specifier_to_int(char c)
{
	if (c == 'o')
		return (8);
	else if (c == 'x' || c == 'X')
		return (16);
	else if (c == 'b' || c == 'B')
		return (2);
	return 10;
}

// char	*ft_fmt_int(t_fmt *fmt, long long n)
// {
// 	char		*result;
// 	long long	nbr;

// 	nbr = n & fmt->length;
// 	if (fmt->specifier == 'd' || fmt->specifier == 'i')
// 		result = ft_ltoa(nbr);
// 	else if (fmt->specifier == 'c')
// 	{
// 		result = ft_strnew(1);
// 		result[0] = (char)n;
// 	}
// 	else
// 		result = ft_ltoa_base(nbr, map_specifier_to_int(fmt->specifier));
// 	if ((fmt->specifier == 'd' || fmt->specifier == 'i')
// 		&& fmt->flags & (FLAG_PLUS_SIGN | FLAG_SPACE) && (long)n > 0)
// 		result = ft_strjoin_free((
// 			fmt->flags & FLAG_PLUS_SIGN ? "+" : " "), result, FALSE, TRUE);
// 	if (fmt->specifier == 'X')
// 		ft_to_upper(result);
// 	if ((fmt->specifier == 'x' || fmt->specifier == 'X')
// 		&& fmt->flags & FLAG_HASHTAG)
// 		result = ft_strjoin_free((
// 			fmt->specifier == 'x' ? "0x" : "0X"), result, FALSE, TRUE);
// 	return (result);
// }

// char	*ft_fmt_ptr(t_fmt *fmt, void *ptr)
// {
// 	char	*result;

// 	if (fmt->specifier == 's')
// 		result = ft_strdup((char *)ptr);
// 	else if (fmt->specifier == 'p')
// 		result = ft_strjoin_free("0x",
// 			ft_ltoa_base((unsigned long long)ptr, 16), FALSE, TRUE);
// 	return (result);
// }

// char	*ft_fmt_width(t_fmt *fmt, char *str)
// {
// 	char *result;
// 	char *padding;
// 	int len;

// 	len = ft_strlen(str);
// 	if (fmt->width <= len)
// 		return str;
// 	if ((fmt->specifier == 'x' || fmt->specifier == 'X')
// 		&& fmt->flags & FLAG_HASHTAG)
// 	{
// 		if (fmt->flags & FLAG_NEGATIVE_SIGN && fmt->flags & FLAG_ZERO)
// 			fmt->flags &= ~FLAG_ZERO;
// 		if (fmt->flags & FLAG_ZERO)
// 			str[1] = '0';
// 	}
// 	padding = ft_strnew(fmt->width - len);
// 	while (fmt->width-- - len)
// 		padding[fmt->width - len] = fmt->flags & FLAG_ZERO ? '0' : ' ';
// 	if (fmt->flags & FLAG_NEGATIVE_SIGN)
// 		result = ft_strjoin_free(str, padding, TRUE, TRUE);
// 	else
// 		result = ft_strjoin_free(padding, str, TRUE, TRUE);
// 	if ((fmt->specifier == 'x' || fmt->specifier == 'X')
// 		&& fmt->flags & FLAG_HASHTAG && fmt->flags & FLAG_ZERO)
// 			result[1] = fmt->specifier == 'x' ? 'x' : 'X';
// 	return result;
// }

// char	*ft_fmt2str(char **str, t_fmt *fmt, va_list args)
// {
// 	char	*result;

// 	if (!fmt->err && fmt->length)
// 		ft_check_length_specifiers(fmt);
// 	if (fmt->err)
// 		return (NULL);
// 	if (ft_strchr(DOUBLE_SPECIFIER, fmt->specifier))
// 		result = ft_fmt_double(fmt, va_arg(args, long double));
// 	else if (ft_strchr(INT_SPECIFIER, fmt->specifier))
// 		result = ft_fmt_int(fmt, va_arg(args, long long));
// 	else if (ft_strchr(PTR_SPECIFIER, fmt->specifier))
// 		result = ft_fmt_ptr(fmt, va_arg(args, void *));
// 	else if (fmt->specifier == '%')
// 	{
// 		result = ft_strnew(1);
// 		result[0] = '%';
// 	}
// 	result = ft_fmt_width(fmt, result);
// 	return (result);
// }

int	ft_valid_fmt(char **head, t_fmt *fmt)
{
	(*head)++;
	ft_parse_flags(head, fmt);
	ft_parse_width(head, fmt);
	ft_parse_precision(head, fmt);
	ft_parse_length(head, fmt);
	ft_parse_specifiers(head, fmt);
	if (!fmt->err)
		ft_check_invalid_length_specifiers(fmt);
	return fmt->err ? FALSE : TRUE;
}

int	ft_dprintf(int fd, const char *str, va_list args)
{
	char	*head;
	t_fmt	fmt;
	char	*result;
	int		len;

	len = 0;
	head = (char *)str;
	while (*head)
	{
		len += ft_strlen_end(head, '%');
		ft_putstr_fd_end(fd, &head, '%');
		if (!*head)
			break;
		ft_bzero(&fmt, sizeof(fmt));
		fmt.args = &args;
		if (ft_valid_fmt(&head, &fmt))
		{
			result = ft_dispatch(&fmt);
			ft_putstr_fd(result, fd);
			len += ft_strlen(result);
			free(result);
		}
		else
			return -1;
	}
	return len;
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	if (!str)
		return 0;
	va_start(args, str);
	result = ft_dprintf(STDOUT_FILENO, str, args);
	va_end(args);
	return result;
}
