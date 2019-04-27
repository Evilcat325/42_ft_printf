/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.part3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:11:30 by evilcat           #+#    #+#             */
/*   Updated: 2019/04/27 03:12:04 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_specifier.h"

char	*ft_spec_unsigned(t_state_t *s, int base, char *alt)
{
	char	*result;

	if(s->fmt.flags.is_left_justify && s->fmt.flags.is_left_pad_zero)
		s->fmt.flags.is_left_pad_zero = FALSE;
	if(s->fmt.flags.is_left_pad_zero && s->fmt.width > s->fmt.percision)
		s->fmt.percision = s->fmt.width;
	if (s->fmt.input.i == 0 && s->fmt.percision == 0 &&
		!(s->fmt.flags.is_force_alt && s->fmt.specifier == 'o'))
		result = ft_strdup("");
	else
	{
		result = ft_ltoa_base(s->fmt.input.u, base);
		if ((int) ft_strlen(result) < s->fmt.percision)
			result = ft_pad_precision(s, result);
		if (result[0] != '0' && s->fmt.flags.is_force_alt)
			result = ft_strjoin_free(alt, result, FALSE, TRUE);
	}
	if ((int) ft_strlen(result) < s->fmt.width)
		result = ft_pad_wid(s, result);
	return result;
}

char	*ft_spec_b(t_state_t *s)
{
	return ft_spec_unsigned(s, 2, "0");
}

char	*ft_spec_o(t_state_t *s)
{
	return ft_spec_unsigned(s, 8, "0");
}

char	*ft_spec_u(t_state_t *s)
{
	return ft_spec_unsigned(s, 10, "");
}

char	*ft_spec_x(t_state_t *s)
{
	char	*result;
	char	*head;
	int		pad_zero_between;

	pad_zero_between =
		s->fmt.flags.is_force_alt && s->fmt.flags.is_left_pad_zero;
	result = ft_spec_unsigned(s, 16, "0x");
	if(pad_zero_between)
	{
		head = result;
		while (*head && *head != 'x')
			head++;
		if (*head == 'x')
			*head = '0';
		result[1] = 'x';
	}
	return (result);
}
