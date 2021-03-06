/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:53:47 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 04:09:03 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PAGE_SIZE 4096

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"
# include "ft_struct.h"
# include "ft_helper.h"
# include "ft_parser.h"
# include "ft_read_input.h"
# include "ft_specifier.h"
# include "ft_formatter.h"

int	ft_printf(const char *str, ...);

#endif
