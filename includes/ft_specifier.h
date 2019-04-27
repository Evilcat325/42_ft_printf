/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 23:17:30 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 20:46:51 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPECIFIER_H
#define FT_SPECIFIER_H

#include "ft_struct.h"
#include "libft.h"
#define ft_spec_err NULL

char			*ft_pad_left_zero(t_state_t *s, char *str);
char			*ft_pad_wid(t_state_t *s, char *str);
char			*ft_spec_d(t_state_t *s);
char			*ft_spec_unsigned(t_state_t *s, int base, char *alt);
char			*ft_spec_b(t_state_t *s);
char			*ft_spec_o(t_state_t *s);
char			*ft_spec_u(t_state_t *s);
char			*ft_spec_x(t_state_t *s);
char			*ft_spec_f(t_state_t *s);
char			*ft_spec_e(t_state_t *s);
char			*ft_spec_g(t_state_t *s);
char			*ft_spec_a(t_state_t *s);
char			*ft_spec_c(t_state_t *s);
char			*ft_spec_s(t_state_t *s);
char			*ft_spec_p(t_state_t *s);
char			*ft_spec_n(t_state_t *s);
char			*ft_spec_z(t_state_t *s);
t_formatter_t	ft_get_formatter(char c);

#endif
