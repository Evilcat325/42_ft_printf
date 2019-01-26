/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:06:08 by seli              #+#    #+#             */
/*   Updated: 2019/01/20 21:56:57 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	void	*cpy;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		if (!(cpy = malloc(content_size)))
			return (NULL);
		ft_memcpy(cpy, content, content_size);
		ptr->content = (void *)cpy;
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
