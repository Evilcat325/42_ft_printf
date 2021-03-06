# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seli <seli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 13:09:56 by seli              #+#    #+#              #
#    Updated: 2019/04/27 03:54:56 by seli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
HEADER = includes
TEST = test.out
LIBFT_HEADER = libft/includes
SOURCES = ft_color.c ft_formatter.c ft_helper.part1.c ft_helper.part2.c	\
			ft_helper.part3.c ft_parser.part1.c ft_parser.part2.c		\
			ft_printf.c ft_read_input.part1.c ft_read_input.part2.c		\
			ft_specifier.part1.c ft_specifier.part2.c ft_specifier.part3.c \
			ft_specifier.part4.c ft_specifier.part5.c ft_specifier.part6.c
SOURCES := $(SOURCES:%.c=src/%.c)
OBJECTS := $(SOURCES:src/%.c=obj/%.o)


all: $(NAME)

$(NAME): object
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT).a ./$(NAME)
	@ar -rcs $(NAME) $(OBJECTS)

object: $(SOURCES)
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(HEADER) -I$(LIBFT_HEADER) -c $(SOURCES)
	@mv *.o obj

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -rf obj

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)

re: fclean all
