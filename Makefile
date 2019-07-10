# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 15:04:02 by yelazrak          #+#    #+#              #
#    Updated: 2019/07/07 16:40:13 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c\
mousse.c \
		

OBJS = $(SRCS:.c=.o)

INCLUDES = fractol.h

CC = gcc 
DD = -lmlx -framework OpenGL -framework AppKit
all: $(NAME)
$(NAME):
	@make  -C libft
	@$(CC) $(SRCS) $(DD) libft/libft.a -I $(INCLUDES) -o  $(NAME)
clean:
	@rm -rf $(OBJS)
	@make clean -C libft
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
re: fclean all
