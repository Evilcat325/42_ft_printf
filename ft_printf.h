/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:53:47 by seli              #+#    #+#             */
/*   Updated: 2019/01/25 17:10:12 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_NEGATIVE_SIGN	1 << 0
# define FLAG_PLUS_SIGN		1 << 1
# define FLAG_SPACE			1 << 2
# define FLAG_HASHTAG		1 << 3
# define FLAG_ZERO			1 << 4

# define ERR_INVALID_SPECIFIER	1 << 0

typedef struct	s_fmt
{
	int			flags;
	int			width;
	int			percision;
	int			length;
	char		sepcifier;
	int			args;
	int			err;
}				t_fmt;

#endif
