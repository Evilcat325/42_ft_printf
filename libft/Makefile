# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evilcat <evilcat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/19 17:52:05 by seli              #+#    #+#              #
#    Updated: 2019/04/26 20:06:23 by evilcat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes
SOURCES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
		ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_isspace.c ft_abs.c ft_lstadd_back.c ft_lstlen.c ft_lstrev.c \
		ft_strjoin_free.c ft_strlen_end.c ft_ltoa_base.c ft_putstr_fd_end.c \
		ft_dtoa.c ft_ltoa.c ft_to_upper.c ft_format_sci.c ft_itoa_max.c
OBJECTS := $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(SOURCES)
	@$(CC) $(CFLAGS) -c $(SOURCES) -I$(HEADER)
	@ar -rcs $(NAME) $(OBJECTS)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
