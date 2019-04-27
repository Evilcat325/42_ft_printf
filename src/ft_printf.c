/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:17:27 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 04:22:47 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_valid_fmt(t_state_t *s)
{
	s->curr++;
	ft_parse(s);
	return (s->fmt.err ? FALSE : TRUE);
}

static void		ft_init_state(t_state_t *s, const char *str, va_list *args)
{
	s->head = (char *)str;
	s->curr = s->head;
	s->len = 0;
	s->args = args;
}

static void		ft_normal_print(t_state_t *s, char buffer[PAGE_SIZE])
{
	size_t		len;

	len = ft_strlen_end(s->curr, '%');
	ft_strncpy(&buffer[s->len], s->curr, len);
	s->curr += len;
	s->len += len;
}

int				ft_dprintf(int fd, const char *str, va_list *args)
{
	char		*result;
	t_state_t	state;
	size_t		len;
	static char	buffer[PAGE_SIZE];

	ft_init_state(&state, str, args);
	while (*state.curr)
		if (*state.curr != '%')
			ft_normal_print(&state, buffer);
		else
		{
			ft_bzero(&state.fmt, sizeof(state.fmt));
			if (!ft_valid_fmt(&state))
				return (-1);
			result = ft_format(&state);
			len = (state.fmt.len ? state.fmt.len : ft_strlen(result));
			ft_strncpy(&buffer[state.len], result, len);
			state.len += len;
			free(result);
		}
	write(fd, buffer, state.len);
	return (state.len);
}

int				ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	if (!str)
		return (0);
	va_start(args, str);
	result = ft_dprintf(STDOUT_FILENO, str, &args);
	va_end(args);
	return (result);
}
