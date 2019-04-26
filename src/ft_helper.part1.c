/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.part1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:11:21 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/25 20:47:22 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_helper.h"

int		ft_is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

int		ft_is_length(char c)
{
	if (c == 'h')
		return 2;
	else if (c == 'l')
		return 3;
	else if (c == 'j')
		return 5;
	else if (c == 'z')
		return 6;
	else if (c == 't')
		return 7;
	else if (c == 'L')
		return 8;
	else
		return FALSE;
}

int		ft_is_two_chars_length(char c)
{
	if (c == 'h')
		return 1;
	else if (c == 'l')
		return 4;
	else
		return FALSE;
}

int		ft_is_specifiers(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X'
		|| c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == "G"
		|| c == 'a' || c == 'A' || c == 'c' || c == 's' || c == 'p' || c == 'n');
}
