/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:50:14 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 03:51:57 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "ft_struct.h"
# include "ft_helper.h"
# include "libft.h"

void	ft_parse_flags(t_state_t *s);
void	ft_parse_width(t_state_t *s);
void	ft_parse_precision(t_state_t *s);
void	ft_parse_length(t_state_t *s);
void	ft_parse_specifiers(t_state_t *s);
void	ft_parse(t_state_t *s);

#endif
