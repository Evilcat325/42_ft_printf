/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 01:20:09 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 01:44:40 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	long	prev_result;
	int		sign;
	char	*head;

	sign = 1;
	result = 0;
	head = (char *)str;
	while (*head == '\t' || *head == '\n' || *head == '\v'
		|| *head == '\f' || *head == '\r' || *head == ' ')
		head++;
	if (*head == '+' || *head == '-')
		sign = *head++ == '-' ? -1 : 1;
	while ('0' <= *head && *head <= '9')
	{
		prev_result = result;
		result = result * 10 + (*head - '0') * sign;
		if (result / 10 != prev_result)
			return (sign == 1 ? -1 : 0);
		head++;
	}
	return ((int)result);
}
