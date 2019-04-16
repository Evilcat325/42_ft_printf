/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:50:19 by seli              #+#    #+#             */
/*   Updated: 2019/04/15 21:38:02 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

formater *ft_dispatch_int_group(t_fmt *fmt)
{
	if (fmt->specifier == 'd')
		return ft_dispatch_d_fmt(fmt);
	// else if (fmt->specifier == 'i')
	// 	return ft_dispatch_i_fmt(fmt);
	// else if (fmt->specifier == 'u')
	// 	return ft_dispatch_u_fmt(fmt);
	// else if (fmt->specifier == 'o')
	// 	return ft_dispatch_o_fmt(fmt);
	// else if (fmt->specifier == 'x')
	// 	return ft_dispatch_x_fmt(fmt);
	// else if (fmt->specifier == 'X')
	// 	return ft_dispatch_xx_fmt(fmt);
	return NULL;
}

formater *ft_dispatch_double_group(t_fmt *fmt)
{
	return NULL;
}

formater *ft_dispatch_string_group(t_fmt *fmt)
{
	return NULL;
}

formater *ft_dispatch_ptr_num_group(t_fmt *fmt)
{
	return NULL;
}

formater *ft_get_formater_group(t_fmt *fmt)
{
	if (ft_is_int_specifier(fmt->specifier))
		return ft_dispatch_int_group(fmt);
}

char *ft_dispatch(t_fmt *fmt, va_list args)
{
	formater	*formater;
	char		*result;

	formater = ft_get_formater(fmt);
	result = formater(fmt);
	return result;
}
