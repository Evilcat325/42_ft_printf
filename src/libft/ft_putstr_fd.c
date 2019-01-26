/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 03:28:55 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 20:22:08 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char *head;

	if (!s)
		return ;
	head = (char *)s;
	while (*head)
	{
		ft_putchar_fd(*head, fd);
		head++;
	}
}
