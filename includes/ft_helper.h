/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:06:06 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 17:28:46 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPER_H
#define FT_HELPER_H

#include "ft_struct.h"

int				ft_is_flag(char c);
t_length_t		ft_is_length(char c);
t_length_t		ft_is_two_chars_length(char c);
int				ft_is_specifiers(char c);
int				ft_is_signed_int_specifier(char c);
int				ft_is_unsigned_int_specifier(char c);
int				ft_is_int_specifier(char c);
int				ft_is_float_specifier(char c);
int				ft_is_string_specifier(char c);
int				ft_is_other_specifier(char c);
int				ft_is_ptr_specifier(char c);

#endif
