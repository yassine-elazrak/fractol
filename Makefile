# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 15:04:02 by yelazrak          #+#    #+#              #
#    Updated: 2019/07/11 15:24:34 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c\
mousse.c \
ft_zoom.c\
fractol_cl.c \
ft_fractol_2_cl.c \
		

OBJS = $(SRCS:.c=.o)

INCLUDES = fractol.h

CC = gcc -Wall -Wextra -Werror
DD = -lmlx -framework OpenGL -framework AppKit -framework OpenCL 
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
