/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:53:47 by seli              #+#    #+#             */
/*   Updated: 2019/01/28 22:32:12 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define FLAG_NEGATIVE_SIGN 1 << 0
# define FLAG_PLUS_SIGN 1 << 1
# define FLAG_SPACE 1 << 2
# define FLAG_HASHTAG 1 << 3
# define FLAG_ZERO 1 << 4
# define FLAG_AOISTRIOHE 1 << 5

# define LENGTH_HH 0x00000000000000FF
# define LENGTH_H 0x000000000000FFFF
# define LENGTH_L 0xFFFFFFFFFFFFFFFF
# define LENGTH_LL 0xFFFFFFFFFFFFFFFF
# define LENGTH_LD 5

# define SPECIFIER "diuoxXfegcsp"
# define DOUBLE_SPECIFIER "feg"
# define INT_SPECIFIER "diuoxXc"
# define PTR_SPECIFIER "sp"

# define ERR_INVALID_SPECIFIER 1
# define ERR_INVALID_LENGTH_WITH_SPECIFIER 2

# define TRUE 1
# define FALSE 0

typedef struct	s_fmt
{
	int				flags;
	int				width;
	int				percision;
	long	long	length;
	char			specifier;
	int				err;
}				t_fmt;

void			ft_read_flags(char **str, t_fmt *fmt);
void			ft_read_width(char **str, t_fmt *fmt, va_list arg);
void			ft_read_precision(char **str, t_fmt *fmt, va_list arg);
void			ft_read_length(char **str, t_fmt *fmt);
void			ft_read_specifiers(char **str, t_fmt *fmt);

#endif
