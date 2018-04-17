# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/22 14:30:08 by tbleuse           #+#    #+#              #
#    Updated: 2018/04/16 14:53:32 by tbleuse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft

MINILIBX = ressources/minilibx_macos/

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDE_MLX = -L $(MINILIBX) -lmlx -framework OpenGL -framework AppKit

SRC_NAME =	main_fdf.c				\
			ft_init_map.c			\
			ft_print_int_tab.c		\
			ft_fdf.c				\
			ft_put_line.c			\
			ft_init_stock.c			\
			ft_all_screen.c			\

SRC = $(addprefix fdf_functions/, $(SRC_NAME))

OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT) :
	@make -C $(LIBFT)

$(MINILIBX) :
	make -C $(MINILIBX)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT)/libft.a $(INCLUDE_MLX) -o $(NAME)
	@echo "$(NAME) have been compiled"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@make clean -C $(LIBFT)
	@make clean -C $(MINILIBX)
	@/bin/rm -f $(OBJ)
	@echo "$(NAME) objects have been deleted"

fclean : clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@echo "$(NAME) have been deleted"

re : fclean all

programs : all clean

.PHONY : all clean fclean re libft $(MINILIBX)
