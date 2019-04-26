/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 03:28:55 by seli              #+#    #+#             */
/*   Updated: 2019/04/25 22:20:10 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(const int fd, const char *str)
{
	size_t len;

	len = ft_strlen(str);
	write(fd, str, len);
	return len;
}
