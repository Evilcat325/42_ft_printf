/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:53:47 by seli              #+#    #+#             */
/*   Updated: 2019/04/15 21:31:21 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include "libft.h"

#define TRUE 1
#define FALSE 0

#define ERR_INVALID_SPECIFIER "Invalid Specifier"
#define ERR_INVALID_SPECIFIER_LENGTH "Invalid Specifier Length"

typedef struct		s_fmt
{
	int				left_justify;
	int				force_sign;
	int				force_space;
	int				force_zero;
	int				force_decimal;
	int				left_pad_zero;
	int				width;
	int				percision;
	int				current_len;
	char			length;
	char			specifier;
	char			*err;
	va_list			*args;
}					t_fmt;

typedef char * formater(t_fmt *fmt);

int		ft_is_flag(char c);
int		ft_is_length(char c);
int		ft_is_two_chars_length(char c);
int		ft_is_specifiers(char c);
void	ft_parse_flags(char **str, t_fmt *fmt);
void	ft_parse_width(char **str, t_fmt *fmt);
void	ft_parse_precision(char **str, t_fmt *fmt);
void	ft_parse_length(char **str, t_fmt *fmt);
void	ft_parse_specifiers(char **str, t_fmt *fmt);

int		ft_is_signed_int_specifier(char c);
int		ft_is_unsigned_int_specifier(char c);
int		ft_is_int_specifier(char c);
int		ft_is_float_specifier(char c);
int		ft_is_string_specifier(char c);
int		ft_is_other_specifier(char c);
int		ft_is_ptr_specifier(char c);

#endif
