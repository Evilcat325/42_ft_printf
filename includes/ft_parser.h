/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:06:43 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 17:41:58 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
#define FT_PARSER_H

#include "ft_struct.h"
#include "ft_helper.h"
#include "libft.h"

void	ft_parse_flags(t_state_t *s);
void	ft_parse_width(t_state_t *s);
void	ft_parse_precision(t_state_t *s);
void	ft_parse_length(t_state_t *s);
void	ft_parse_specifiers(t_state_t *s);
void	ft_parse(t_state_t *s);

#endif
