# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 00:40:44 by ojebbari          #+#    #+#              #
#    Updated: 2023/05/16 21:10:14 by ojebbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractal.c mandelbrot.c julia.c mouse.c hook.c
CFLAGS = -Wall -Wextra -Werror
CC = CC
NAME = FRACTAL
RM = rm -fr
BNS = fractal_bonus.o
FRMWORK = -lmlx -framework OpenGL -framework AppKit 
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJ)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a $(FRMWORK) -o $@

bonus : all $(BNS)
	@$(CC) $(CFLAGS) $(BNS) -o $(NAME)

$(OBJ) : fractal.h
$(BNS) : fractal_bonus.h

clean :
	@cd ft_printf && make clean
	@$(RM) $(OBJ)

fclean : clean
	@cd ft_printf && make fclean
	@$(RM) $(NAME)
	@$(RM) $(BNS)

re : fclean all