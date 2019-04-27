/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 01:44:15 by seli              #+#    #+#             */
/*   Updated: 2019/04/26 22:34:35 by evilcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_valid_fmt(t_state_t *s)
{
	s->curr++;
	ft_parse(s);
	return s->fmt.err ? FALSE : TRUE;
}

int	ft_dprintf(int fd, const char *str, va_list *args)
{
	char		*result;
	t_state_t	state;

	state.curr = state.head = (char *) str;
	state.len = 0;
	state.args = args;
	while (*state.curr)
		if (*state.curr != '%')
			state.len += ft_putstr_fd_end(&state.curr, fd, '%');
		else
		{
			ft_bzero(&state.fmt, sizeof(state.fmt));
			if (!ft_valid_fmt(&state))
				return -1;
			result = ft_format(&state);
			if (!state.fmt.len)
				state.len += ft_putstr_fd(result, fd);
			else
				state.len += write(fd, result, state.fmt.len);
			free(result);
		}
	return state.len;
}


int ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	if (!str)
		return 0;
	va_start(args, str);
	result = ft_dprintf(STDOUT_FILENO, str, &args);
	va_end(args);
	return result;
}
