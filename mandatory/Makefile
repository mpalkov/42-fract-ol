# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 11:11:18 by mpalkov           #+#    #+#              #
#    Updated: 2023/06/16 11:11:22 by mpalkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MODE	:= debug

ifeq ($(MODE),debug)
	CFLAGS	+= -g3
endif

NAME	:=	fractol

#-------------------------------------------------------------------------------
#		FILES

SRCS	:=	fractol.c \
			f_burningship.c \
			f_mandelbrot.c \
			f_julia.c \
			exit.c \
			handle_mouse.c \
			utils.c \
			initialize.c

#-------------------------------------------------------------------------------
#		COLORS

DEFCOLOR	:=	\033[0;39m
GRAY		:=	\033[0;90m
RED			:=	\033[0;91m
ORANGE		:=	\033[0;33m
GREEN		:=	\033[0;92m
YELLOW		:=	\033[0;93m
BLUE		:=	\033[0;94m
MAGENTA		:=	\033[0;95m
CYAN		:=	\033[0;96m
WHITE		:=	\033[0;97m

#-------------------------------------------------------------------------------
#		DIRECTORIES

LIBFT_DIR	:=	libft/

MLX_DIR		:=	mlx/

OBJ_DIR		:=	.obj/

SRC_DIR		:=	src/

#-------------------------------------------------------------------------------
#		COMMANDS

CC		:=	cc

CFLAGS	+=	-MMD -MP -MT $@

# CFLAGS	+=	-Wall -Werror -Wextra

CFLAGS	+=	-framework OpenGL -framework AppKit

RM		:=	rm -f

CP		:=	cp -f

MAKEFLAGS	:=	--no-print-directory

#-------------------------------------------------------------------------------
#		RULES

LIBFT	:=	$(LIBFT_DIR)/libft.a

MLX		:=	$(MLX_DIR)/libmlx.a

OBJS	:=	$(addprefix $(OBJ_DIR),$(SRCS:.c=.o))

DEPS	:=	$(addsuffix .d,$(basename $(OBJS)))

INCLUDE	:=	-Ilibft/ -Imlx/ -Iinclude/

all:	make_libft make_mlx $(NAME)

make_libft:
	@echo "$(GREEN) Calling libft make$(DEFCOLOR)"
	$(MAKE) -C $(LIBFT_DIR)

make_mlx:
	@echo "$(GREEN) Calling mlx make$(DEFCOLOR)"
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) Compiling: $< -> $@$(DEFCOLOR)"

-include $(DEPS)

$(NAME): $(OBJS) $(LIBFT) 
	@echo "Creating binary $@"
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -o $@
	@echo "$(GREEN)	ALL DONE$(DEFCOLOR)"

clean:
	@echo "$(ORANGE)	Cleaning residual .o and .d files$(DEFCOLOR)"
	$(MAKE) clean -sC $(LIBFT_DIR)
	@echo "$(ORANGE)	Mlx clean$(DEFCOLOR)"
	$(MAKE) clean -sC $(MLX_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(ORANGE)	Cleaning main binary files$(DEFCOLOR)"
	$(RM) $(NAME)
	@echo "$(ORANGE)	Libft fclean$(DEFCOLOR)"
	$(MAKE) fclean -sC $(LIBFT_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:	all, clean, fclean, re
