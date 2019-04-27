/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:52:10 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 17:38:16 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
#define FT_STRUCT_H

#include <stdarg.h>
#include <stddef.h>
#include <wchar.h>
#include <stdint.h>

typedef struct		s_flags
{
	unsigned int	is_left_justify : 1;
	unsigned int	is_force_sign : 1;
	unsigned int	is_force_space : 1;
	unsigned int	is_force_alt : 1;
	unsigned int	is_left_pad_zero : 1;
	unsigned int	is_uppercase : 1;
}					t_flags_t;

typedef enum		e_length
{
	NONE,
	hh,
	h,
	l,
	ll,
	j,
	z,
	t,
	L
}					t_length_t;

typedef union		u_input
{
	intmax_t		i;
	uintmax_t		u;
	long double		f;
	void			*p;
}					t_input_t;

typedef struct		s_fmt
{
	t_flags_t		flags;
	unsigned int	width;
	unsigned int	percision;
	t_length_t		length;
	char			specifier;
	char			*err;
	t_input_t		input;
	size_t			len;
}					t_fmt_t;

typedef struct		s_state
{
	t_fmt_t			fmt;
	char			*head;
	char			*curr;
	size_t			len;
	va_list			*args;
}					t_state_t;

typedef char		*(*t_formatter_t)(t_state_t *s);
typedef int			(*t_inputter_t)(t_state_t *s);

#define TRUE 1
#define FALSE 0
#define ERR_INVALID_SPECIFIER "Invalid Specifier"
#define ERR_INVALID_SPECIFIER_LENGTH "Invalid Specifier Length"
#define LOWWER 0x20

#endif
