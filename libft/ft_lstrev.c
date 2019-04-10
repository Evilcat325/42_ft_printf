/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:49:11 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 22:50:27 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstrev(t_list **alst)
{
	t_list	*next;
	t_list	*prev;

	next = 0;
	prev = 0;
	if (!alst || !*alst || !(*alst)->next)
		return ;
	while (*alst)
	{
		next = (*alst)->next;
		(*alst)->next = prev;
		prev = (*alst);
		(*alst) = next;
	}
	*alst = prev;
}
