/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:22:26 by seli              #+#    #+#             */
/*   Updated: 2019/04/15 21:37:26 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dispatch_d.h"

char		*ft_dispatch_d_n(t_fmt *fmt)
{
	int		d;

	d = va_arg(*(fmt->args), int);
	return ft_itoa(d);
}

char		*ft_dispatch_d_hh(t_fmt *fmt)
{
	signed char		d;

	d = va_arg(*(fmt->args), signed char);
	return ft_itoa(d);
}

char		*ft_dispatch_d_h(t_fmt *fmt)
{
	short int		d;

	d = va_arg(*(fmt->args), short int);
	return ft_itoa(d);
}

char		*ft_dispatch_d_l(t_fmt *fmt)
{
	long int		d;

	d = va_arg(*(fmt->args), long int);
	return ft_itoa(d);
}

char		*ft_dispatch_d_ll(t_fmt *fmt)
{
	long long int	d;

	d = va_arg(*(fmt->args), long long int);
	return ft_itoa(d);
}

char		*ft_dispatch_d_j(t_fmt *fmt)
{
	intmax_t		d;

	d = va_arg(*(fmt->args), intmax_t);
	return ft_itoa(d);
}

char		*ft_dispatch_d_z(t_fmt *fmt)
{
	size_t		d;

	d = va_arg(*(fmt->args), size_t);
	return ft_itoa(d);
}

char		*ft_dispatch_d_tt(t_fmt *fmt)
{
	ptrdiff_t		d;

	d = va_arg(*(fmt->args), ptrdiff_t);
	return ft_itoa(d);
}

formater	*ft_dispatch_d_fmt(t_fmt *fmt)
{
	if (fmt->length == 'n')
		return ft_dispatch_d_n;
	else if (fmt->length == 'H')
		return ft_dispatch_d_hh;
	else if (fmt->length =='h')
		return ft_dispatch_d_h;
	else if (fmt->length == 'l')
		return ft_dispatch_d_l;
	else if (fmt->length == 'll')
		return ft_dispatch_d_ll;
	else if (fmt->length == 'j')
		return ft_dispatch_d_j;
	else if (fmt->length == 'z')
		return ft_dispatch_d_z;
	else if (fmt->length == 't')
		return ft_dispatch_d_tt;
	else
		return NULL;
}
