/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:18:40 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 03:47:16 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd_end(char **str, const int fd, char end)
{
	size_t len;

	len = ft_strlen_end(*str, end);
	write(fd, *str, len);
	(*str) += len;
	return (len);
}
