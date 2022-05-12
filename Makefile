# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 18:03:49 by lzima             #+#    #+#              #
#    Updated: 2022/04/27 10:51:48 by lzima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
BLUE	= \033[0;34m
WHITE	=\033[0;37m
BUILD	= \e[38;5;225m
SEP		= \e[38;5;120m
DUCK	= \e[38;5;227m
RESET	= \033[0m

# COLORS


SRC				= ./src/libft_utils.c \
				 ./src/hook.c \
				 ./src/init.c \
				 ./src/mandelbrot.c \
				 ./src/memory.c \
				 ./src/julia.c \
				 ./src/draw_n_paint.c \
				 ./src/utils.c \
				 ./src/main.c

MAKEMLX			= ${MAKE} -C ${MLX}
MLX				= ./lib/mlx

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address -Imlx

MLXFLAGS 		= -Llib/mlx -lmlx -framework OpenGL -framework AppKit

NAME			= fractol

OBJS			= ${SRC:.c=.o}

${NAME}:		${OBJS}
				${MAKEMLX}
				${CC} ${CFLAGS} ${MLXFLAGS} -o ${NAME} ${OBJS}
				@printf "\n ${ORANGE}🧠 Usage: ./fractol <set>\n"
				@printf "\n--- Set available ---\n"
				@printf "\n | mandelbrot | julia |\n"
				@printf "\n--- Keycode glossary --- \n"
				@printf "\n${RED}🌈 R: change RED color\n"
				@printf "\n${GREEN}🌈 L: change GREEN color\n"
				@printf "\n${BLUE}🌈 O: change BLUE color\n"
				@printf "\n${ORANGE}🌈 S: change ALL color\n"
				@printf "\n ${WHITE}🐭 Scroll Up | Down: Zoom IN | Zoom OUT \n"
				@printf "\n\n ESC: exit program\n\n"
.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:			${NAME}

clean:
				${RM} ${OBJS}
				${MAKEMLX} clean
				@printf "\n${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n\n"


fclean:			clean
				${RM} ${NAME}
				${MAKEMLX} fclean
				@printf "${RED} 💥 Deleted ${NAME} files${RESET} ❌\n\n"

re:				fclean all

norm :
				@${MAKEMLX} ${LIBUTILS} norm
				@printf "${DUCK} 🐥 Checking Norm for ${NAME}${RESET}\n"
				@norminette ${SRCS}
				@norminette ${HEADS_DIR}

.PHONY : all clean fclean re norm


