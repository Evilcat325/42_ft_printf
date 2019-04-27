/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:50:31 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 03:52:23 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_INPUT_H
# define FT_READ_INPUT_H
# include "ft_struct.h"
# define FT_INPUT_ERR NULL

int				ft_input_signed(t_state_t *s);
int				ft_input_unsigned(t_state_t *s);
int				ft_input_float(t_state_t *s);
int				ft_input_c(t_state_t *s);
int				ft_input_s(t_state_t *s);
int				ft_input_p(t_state_t *s);
int				ft_input_n(t_state_t *s);
int				ft_input_z(t_state_t *s);
t_inputter_t	ft_get_inputter(char c);

#endif
