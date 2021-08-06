# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 15:37:00 by esormune          #+#    #+#              #
#    Updated: 2021/04/20 15:49:00 by esormune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

# directories
SRC_DIR = ./src/
INC_DIR = ./includes/
OBJ_DIR = ./obj/
LIBFT_DIR = ./libft/
MLX_DIR = ./minilibx/

#source files
SRC_FILES = main.c fr_valid.c fr_init.c fr_events.c fr_draw.c fr_fractals.c \
	fr_reset.c fr_mouse.c fr_text.c fr_render.c fr_fractals_cont.c
OBJ_FILES = $(SRC_FILES:.c=.o)

#paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MLX = $(addprefix $(MLX_DIR), libmlx.a)

#link libft and minilibx
LNK = -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx \
	-L /opt/X11/lib -l Xext -lX11 \
	-framework OpenGL -framework AppKit 

all: obj $(LIBFT) $(MLX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) \
		-o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MLX):
	@make -C $(MLX_DIR)

# compilation
$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "$(NAME) compiled."

# cleaning rules
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "Object files deleted."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(NAME) deleted."

# re
re: fclean all

# phony
.PHONY = clean fclean all re
