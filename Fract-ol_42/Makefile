# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 00:40:44 by ojebbari          #+#    #+#              #
#    Updated: 2023/05/21 06:01:13 by ojebbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractal.c mandelbrot.c julia.c hook.c utils.c utils2.c
CFLAGS = -Wall -Wextra -Werror 
CC = cc
NAME = FRACTOL
RM = rm -fr
BNS =fractal_bonus.c Tricorn_bonus.c mandelbrot.c julia.c hook.c utils.c \
		utils2.c utils3.c color.c julia_bonus.c mandelbrot_bonus.c
FRMWORK = -lmlx -framework OpenGL -framework AppKit 

OBJ = $(SRC:.c=.o)
OBJBNS = $(BNS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C printf
	@$(CC) $(CFLAGS) $(OBJ) ./printf/libftprintf.a $(FRMWORK) -o $@

bonus :$(OBJBNS)
	@make -C printf
	@$(CC) $(CFLAGS) $(OBJBNS) ./printf/libftprintf.a $(FRMWORK) -o $(NAME) 

$(OBJ) : fractal.h
$(OBJBNS) : fractal_bonus.h

clean :
	@cd printf && make clean
	@$(RM) $(OBJ)

fclean : clean
	@cd printf && make fclean
	@$(RM) $(NAME)
	@$(RM) $(OBJBNS)

re : fclean all