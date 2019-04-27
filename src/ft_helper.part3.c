/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.part3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:17:08 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 03:17:09 by seli             ###   ########.fr       */
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
