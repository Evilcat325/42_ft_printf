/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:36:12 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 22:25:17 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	dummy;
	t_list	*head;
	t_list	*prev;

	head = lst;
	dummy.next = head;
	prev = &dummy;
	while (head != NULL)
	{
		prev->next = ft_lstnew(f(head)->content, f(head)->content_size);
		if (!prev->next)
		{
			head = dummy.next;
			while (head != NULL)
			{
				prev = head->next;
				free(head);
				head = prev;
			}
			return (NULL);
		}
		prev = prev->next;
		head = head->next;
	}
	return (dummy.next);
}
