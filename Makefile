#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 15:48:19 by mponomar          #+#    #+#              #
#    Updated: 2018/02/24 15:00:48 by mponomar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_Flags = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL \
			-framework AppKit

SRC = src/
INC = includes/
LIBFT = libft/
FT_INC = $(LIBFT)/includes

FdF_CMP =   main.o

all: $(NAME)

$(NAME): $(FdF_CMP)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(MLX_Flags) -o $(NAME) -L $(LIBFT) -lft $(FdF_CMP)
	@echo "made" $(NAME)

$(FdF_CMP): %.o: $(SRC)%.c
	@$(CC) -c $(FLAGS) -I $(FT_INC) -I $(INC) $< -o $@

clean:
	@-/bin/rm -f $(FdF_CMP)
	@-make clean -C $(LIBFT)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@-make fclean -C $(LIBFT)
	@echo "fcleaned" $(NAME)

re: fclean all

rmf:
	rm *~
	rm \#*
	rm *.out