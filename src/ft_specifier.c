/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:50:19 by seli              #+#    #+#             */
/*   Updated: 2019/04/25 21:40:12 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef void (*Handler)(void);

void *ft_spec_err(void);
void *ft_spec_d(void);
void *ft_spec_i(void);
void *ft_spec_u(void);
void *ft_spec_o(void);
void *ft_spec_x(void);
void *ft_spec_f(void);
void *ft_spec_e(void);
void *ft_spec_g(void);
void *ft_spec_a(void);
void *ft_spec_c(void);
void *ft_spec_s(void);
void *ft_spec_p(void);
void *ft_spec_n(void);
void *ft_spec_b(void);

// start from a
Handler table[] = {
	ft_spec_a,		ft_spec_b,		ft_spec_c,		ft_spec_d,
	ft_spec_e,		ft_spec_f,		ft_spec_g,		ft_spec_err,
	ft_spec_i,		ft_spec_err,	ft_spec_err,	ft_spec_err,
	ft_spec_err,	ft_spec_n,		ft_spec_o,		ft_spec_p,
	ft_spec_err,	ft_spec_err,	ft_spec_s,		ft_spec_err,
	ft_spec_u,		ft_spec_err,	ft_spec_err,	ft_spec_x,
	ft_spec_err,	ft_spec_err
}
