/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 23:04:36 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/26 17:46:32 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_formatter.h"

char	*ft_format(t_state_t *s)
{
	void			*func;
	char			*result;

	if((func = ft_get_inputter(s->fmt.specifier)) == NULL)
		return (NULL);
	(*(t_inputter_t)func)(s);
	if((func = ft_get_formatter(s->fmt.specifier)) == NULL)
		return (NULL);
	result = (*(t_formatter_t)func)(s);
	return result;
}
