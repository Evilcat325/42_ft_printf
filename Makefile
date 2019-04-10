# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seli <seli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 13:09:56 by seli              #+#    #+#              #
#    Updated: 2019/04/10 14:34:42 by seli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
HEADER = includes
TEST = test
LIBFT_HEADER = libft/includes
SOURCES = ft_color.c ft_format_read.c ft_printf.c
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

test: $(NAME)
	@$(CC) $(FLAGS) -I(HEADER) -L$(NAME) test.c -o $(TEST)
	@./$(TEST)

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -rf obj

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)

re: fclean all
