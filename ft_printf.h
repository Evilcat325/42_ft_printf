/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:53:47 by seli              #+#    #+#             */
/*   Updated: 2019/01/26 18:51:53 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_NEGATIVE_SIGN	1 << 0
# define FLAG_PLUS_SIGN		1 << 1
# define FLAG_SPACE			1 << 2
# define FLAG_HASHTAG		1 << 3
# define FLAG_ZERO			1 << 4

# define LENGTH_HH			1
# define LENGTH_H			2
# define LENGTH_L			3
# define LENGTH_LL			4
# define LENGTH_J			5
# define LENGTH_Z			6
# define LENGTH_T			7
# define LENGTH_LD			8

# define SPECIFIER "diuoxXfFeEgGaAcspn"
# define DOUBLE_SPECIFIER "fFeEgGaA"
# define INT_SPECIFIER "diuoxXc"
# define PTR_SPECIFIER "spn"

# define ERR_INVALID_SPECIFIER				1
# define ERR_INVALID_LENGTH_WITH_SPECIFIER	2

# define TRUE				1
# define FALSE				0

typedef struct	s_fmt
{
	int			flags;
	int			width;
	int			percision;
	int			length;
	char		specifier;
	int			err;
}				t_fmt;

#endif
