/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:35:29 by seli              #+#    #+#             */
/*   Updated: 2019/04/15 21:37:19 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPATCH_D_H
#define FT_DISPATCH_D_H

#include "ft_printf.h"

char		*ft_dispatch_d_n(t_fmt *fmt);
char		*ft_dispatch_d_hh(t_fmt *fmt);
char		*ft_dispatch_d_h(t_fmt *fmt);
char		*ft_dispatch_d_l(t_fmt *fmt);
char		*ft_dispatch_d_ll(t_fmt *fmt);
char		*ft_dispatch_d_j(t_fmt *fmt);
char		*ft_dispatch_d_z(t_fmt *fmt);
char		*ft_dispatch_d_tt(t_fmt *fmt);
formater	*ft_dispatch_d_fmt(t_fmt *fmt);

#endif
