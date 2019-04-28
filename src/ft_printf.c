/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 03:17:27 by seli              #+#    #+#             */
/*   Updated: 2019/04/27 20:11:22 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init_state(t_state_t *s, const char *str, va_list *args)
{
	s->head = (char *)str;
	s->curr = s->head;
	s->len = 0;
	s->args = args;
	s->buffer = ft_strnew(0);
}

static void		ft_normal_print(t_state_t *s)
{
	size_t		len;
	char		*dup;

	len = ft_strlen_end(s->curr, '%');
	dup = ft_strnew(s->len + len);
	ft_strncpy_force(dup, s->buffer, s->len);
	ft_strncpy_force(dup + s->len, s->curr, len);
	free(s->buffer);
	s->buffer = dup;
	s->curr += len;
	s->len += len;
}

static int		ft_format_print(t_state_t *s)
{
	size_t		len;
	int			i;
	char		*tmp;
	char		*dup;

	ft_bzero(&s->fmt, sizeof(s->fmt));
	s->curr++;
	ft_parse(s);
	if (s->fmt.err)
		return (FALSE);
	tmp = ft_format(s);
	len = (s->fmt.len ? s->fmt.len : ft_strlen(tmp));
	dup = ft_strnew(s->len + len);
	ft_strncpy_force(dup, s->buffer, s->len);
	ft_strncpy_force(dup + s->len, tmp, len);
	free(tmp);
	free(s->buffer);
	s->buffer = dup;
	s->len += len;
	return (TRUE);
}

int				ft_dprintf(int fd, const char *str, va_list *args)
{
	t_state_t	state;

	ft_init_state(&state, str, args);
	while (*state.curr)
		if (*state.curr != '%')
			ft_normal_print(&state);
		else if (ft_format_print(&state) == FALSE)
		{
			free(state.buffer);
			return (-1);
		}
	write(fd, state.buffer, state.len);
	free(state.buffer);
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
