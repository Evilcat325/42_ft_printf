/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:44:15 by seli              #+#    #+#             */
/*   Updated: 2019/01/26 14:56:24 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
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

void	ft_read_width(char **str, t_fmt *fmt)
{
	if (**str == '*')
	{
		fmt->width = -1;
		fmt->args++;
		(*str)++;
	}
	else if (ft_isdigit(**str))
		fmt->width = ft_atoi(*str);
	while (ft_isdigit(**str) || **str == '*')
		(*str)++;
}

void	ft_read_precision(char **str, t_fmt *fmt)
{
	if (**str == '.')
	{
		(*str)++;
		fmt->percision = ft_atoi(*str);
	}
}

void	ft_putstr_fmt(int fd, char **str, t_fmt *fmt)
{
	ft_read_flags(str, fmt);
	ft_read_width(str, fmt);
	ft_read_precision(str, fmt);
	ft_read_length(str, fmt);
	ft_read_specifiers(str, fmt);
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
		ft_putstr_fmt(fd, &head, &fmt);
		if (ft_check_fmt(&fmt))
		{
		}
	}
	va_end(args);
}
