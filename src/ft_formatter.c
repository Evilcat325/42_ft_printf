/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:16:52 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 03:16:52 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_formatter.h"

char	*ft_format(t_state_t *s)
{
	void			*func;
	char			*result;

	if ((func = ft_get_inputter(s->fmt.specifier)) == NULL)
		return (NULL);
	(*(t_inputter_t)func)(s);
	if ((func = ft_get_formatter(s->fmt.specifier)) == NULL)
		return (NULL);
	result = (*(t_formatter_t)func)(s);
	if (s->fmt.flags.is_uppercase)
		ft_to_upper(result);
	return (result);
}
