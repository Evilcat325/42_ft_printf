/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.part3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:39:32 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/25 23:06:49 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ft_is_string_specifier(char c)
{
	return (c == 'c' || c == 's');
}

int		ft_is_other_specifier(char c)
{
	return (c == 'n');
}

int		ft_is_ptr_specifier(char c)
{
	return (c == 'p');
}
