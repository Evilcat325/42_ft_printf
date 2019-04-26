/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:06:43 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/25 21:38:20 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
#define FT_PARSER_H

#include "ft_struct.h"

void	ft_parse_flags(char **str, t_flags *flag);
void	ft_parse_width(char **str, t_fmt *fmt);
void	ft_parse_precision(char **str, t_fmt *fmt);
void	ft_parse_length(char **str, t_fmt *fmt);
void	ft_parse_specifiers(char **str, t_fmt *fmt);
void	ft_parse(char **str, t_fmt *fmt);

#endif
