/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:52:10 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/25 21:33:05 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
#define FT_STRUCT_H

#include <stdarg.h>
#include "ft_struct.h"

typedef struct		s_flags
{
	unsigned int	is_left_justify : 1;
	unsigned int	is_force_sign : 1;
	unsigned int	is_force_space : 1;
	unsigned int	is_force_alt : 1;
	unsigned int	is_left_pad_zero : 1;
	unsigned int	is_uppercase : 1;
}					t_flags;

typedef struct		s_fmt
{
	t_flags			flags;
	int				width;
	int				percision;
	char			length;
	char			specifier;
	char			*err;
	va_list			*args;
}					t_fmt;

typedef struct		s_state
{
	t_fmt			fmt;
	int				current_len;
}					t_state;

typedef char (*formater)(t_state *state);

#define TRUE 1
#define FALSE 0
#define ERR_INVALID_SPECIFIER "Invalid Specifier"
#define ERR_INVALID_SPECIFIER_LENGTH "Invalid Specifier Length"
#define LOWWER 0x20

#endif
