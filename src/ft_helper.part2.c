/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:39:00 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/25 21:39:25 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_helper.h"

int		ft_is_signed_int_specifier(char c)
{
	return (c == 'd' || c == 'i');
}

int		ft_is_unsigned_int_specifier(char c)
{
	return (c == 'o' || c == 'u' || c == 'x' || c == 'X'
			|| c == 'b' || c == 'B');
}

int		ft_is_int_specifier(char c)
{
	return (ft_is_signed_int_specifier(c) || ft_is_unsigned_int_specifier(c));
}

int		ft_is_float_specifier(char c)
{
	return (c == 'f' || c == 'F' || c == 'e' || c == 'E'
		|| c == 'g' || c == 'G' || c == 'a' || c == 'A');
}
