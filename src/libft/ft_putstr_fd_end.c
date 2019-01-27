/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 02:53:47 by seli              #+#    #+#             */
/*   Updated: 2019/01/27 02:54:06 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd_end(int fd, char **str, char end)
{
	size_t len;

	len = ft_strlen_end(*str, end);
	write(fd, *str, len);
	*str += len;
}
