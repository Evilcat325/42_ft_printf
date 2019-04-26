/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:53:47 by seli              #+#    #+#             */
/*   Updated: 2019/04/25 22:30:44 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd_end(char **str, const int fd, char end)
{
	size_t len;

	len = ft_strlen_end(*str, end);
	write(fd, *str, len);
	(*str) += len;
	return len;
}
