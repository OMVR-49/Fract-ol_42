# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 00:40:44 by ojebbari          #+#    #+#              #
#    Updated: 2023/05/20 17:58:30 by ojebbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fractal.c mandelbrot.c julia.c hook.c utils.c
CFLAGS = -Wall -Wextra -Werror
CC = CC
NAME = FRACTOL
RM = rm -fr
BNS =fractal_bonus.c hook_bonus.c mandelbrot_bonus.c julia_bonus.c \
		color_bonus.c utils_bonus.c
FRMWORK = -lmlx -framework OpenGL -framework AppKit 

OBJ = $(SRC:.c=.o)

OBJBNS = $(BNS:.c=.o)

all : $(NAME)

%.o: %.c fractal.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJ)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a $(FRMWORK) -o $@

bonus :$(OBJBNS)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(BNS) ./ft_printf/libftprintf.a $(FRMWORK) -o $(NAME) 

$(OBJ) : fractal.h
$(OBJBNS) : fractal_bonus.h

clean :
	@cd ft_printf && make clean
	@$(RM) $(OBJ)

fclean : clean
	@cd ft_printf && make fclean
	@$(RM) $(NAME)
	@$(RM) $(OBJBNS)

re : fclean all