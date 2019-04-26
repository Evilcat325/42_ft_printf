/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 23:04:36 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 00:19:24 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_formatter.h"

char	*ft_format(t_state_t *s)
{
	void			*func;
	char			*result;

	if((func = ft_get_inputter(s->fmt.specifier)) == NULL)
		return (NULL);
	((t_inputter_t)func)(s);
	if((func = ft_get_formatter(s->fmt.specifier)) == NULL)
		return (NULL);
	result = ((t_formatter_t)func);
}

// char	*ft_fmt_t_double(t_fmt_t *fmt, long double n)
// {
// 	char		*result;

// 	result = ft_dtoa(n, fmt->percision);
// 	if (fmt->flags & FLAG_PLUS_SIGN && (long)n > 0)
// 		result = ft_strjoin_free("+", result, FALSE, TRUE);
// 	else if (fmt->flags & FLAG_SPACE && (long)n > 0)
// 		result = ft_strjoin_free(" ", result, FALSE, TRUE);
// 	return (result);
// }

// char	*ft_fmt_t_int(t_fmt_t *fmt, long long n)
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

// char	*ft_fmt_t_ptr(t_fmt_t *fmt, void *ptr)
// {
// 	char	*result;

// 	if (fmt->specifier == 's')
// 		result = ft_strdup((char *)ptr);
// 	else if (fmt->specifier == 'p')
// 		result = ft_strjoin_free("0x",
// 			ft_ltoa_base((unsigned long long)ptr, 16), FALSE, TRUE);
// 	return (result);
// }

// char	*ft_fmt_t_width(t_fmt_t *fmt, char *str)
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

// char	*ft_fmt_t2str(char **str, t_fmt_t *fmt, va_list args)
// {
// 	char	*result;

// 	if (!fmt->err && fmt->length)
// 		ft_check_length_specifiers(fmt);
// 	if (fmt->err)
// 		return (NULL);
// 	if (ft_strchr(DOUBLE_SPECIFIER, fmt->specifier))
// 		result = ft_fmt_t_double(fmt, va_arg(args, long double));
// 	else if (ft_strchr(INT_SPECIFIER, fmt->specifier))
// 		result = ft_fmt_t_int(fmt, va_arg(args, long long));
// 	else if (ft_strchr(PTR_SPECIFIER, fmt->specifier))
// 		result = ft_fmt_t_ptr(fmt, va_arg(args, void *));
// 	else if (fmt->specifier == '%')
// 	{
// 		result = ft_strnew(1);
// 		result[0] = '%';
// 	}
// 	result = ft_fmt_t_width(fmt, result);
// 	return (result);
// }
