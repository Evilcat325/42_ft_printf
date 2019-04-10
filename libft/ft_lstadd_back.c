/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:43:49 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 22:45:47 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*head;

	if (!new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		head = *alst;
		while (head->next)
			head = head->next;
		head->next = new;
	}
}
