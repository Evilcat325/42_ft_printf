/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:13:19 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 22:04:29 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*head;

	if (!alst || !*alst)
		return ;
	head = *alst;
	while (head != NULL)
	{
		next = head->next;
		del(head->content, head->content_size);
		free(head);
		head = next;
	}
	*alst = NULL;
}
