# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:58:04 by jvarila           #+#    #+#              #
#    Updated: 2024/11/27 08:10:32 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -crs

SRCDIR = ./src/
INC = ./include/

HF = $(INC)libftprintf.h

SRC =	$(SRCDIR)ft_printf.c \
	$(SRCDIR)handle_c.c \
	$(SRCDIR)handle_s.c \
	$(SRCDIR)handle_p.c \
	$(SRCDIR)handle_d.c \
	$(SRCDIR)handle_i.c \
	$(SRCDIR)handle_u.c \
	$(SRCDIR)handle_hex_lowercase.c \
	$(SRCDIR)handle_hex_uppercase.c \
	$(SRCDIR)handle_percentage.c \
	$(SRCDIR)write_till_char.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HF) ./libft/libft.a
	cp ./libft/libft.a ./
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

./libft/libft.a: phony
	@make -C ./libft/

clean:
	@make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

phony:

.PHONY: clean fclean re bonus phony
