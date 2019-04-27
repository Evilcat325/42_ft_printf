/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:16:59 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 03:17:00 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_helper.h"

int				ft_is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

t_length_t		ft_is_length(char c)
{
	if (c == 'h')
		return (h);
	else if (c == 'l')
		return (l);
	else if (c == 'j')
		return (j);
	else if (c == 'z')
		return (z);
	else if (c == 't')
		return (t);
	else if (c == 'L')
		return (L);
	else
		return (NONE);
}

t_length_t		ft_is_two_chars_length(char c)
{
	if (c == 'h')
		return (hh);
	else if (c == 'l')
		return (ll);
	else
		return (NONE);
}

int				ft_is_specifiers(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'U' || c == 'o'
		|| c == 'x' || c == 'X' || c == 'f' || c == 'F' || c == 'e'
		|| c == 'E' || c == 'g' || c == 'G' || c == 'a' || c == 'A'
		|| c == 'c' || c == 's' || c == 'p' || c == 'n' || c == '%');
}
