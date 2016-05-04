# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 08:59:28 by tglaudel          #+#    #+#              #
#    Updated: 2016/05/04 14:57:18 by tglaudel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH_ASM = srcs/asm

SRC_PATH_COR = srcs/corewar

SRC_NAME_ASM = main.c \
			   get_opt.c \
			   get_args.c \
			   check_format.c \
			   format_comment_name.c \
			   format_label.c \
			   format_cmd.c \
			   get_cmd.c \
			   create_odc.c \
			   convert_to_octet.c \
			   is_something.c \
			   create_file.c \
			   utils.c \
			   print.c \
			   print_help.c \
			   free_all.c \

SRC_NAME_COR = op.c \
			   main.c \
			   get_opt.c \
			   print_help.c \
			   is_something.c \
			   champ.c \
			   memory.c \
			   init.c \
			   ncurses.c \
			   processus.c \
			   game_loop.c \
			   print.c \
			   conversion.c \
			   parsing_instruction.c \
			   check_proc_cycle.c \
			   live.c \
			   ld.c \
			   zjmp.c \
			   st.c \



SRC_ASM = $(addprefix $(SRC_PATH_ASM)/,$(SRC_NAME_ASM))

SRC_COR = $(addprefix $(SRC_PATH_COR)/,$(SRC_NAME_COR))

OBJ_ASM = $(SRC_ASM:.c=.o)

OBJ_COR = $(SRC_COR:.c=.o)

NAME_ASM = asm

NAME_COR = corewar

CC = gcc

LIBFT = libft/libft.a

CFLAGS = -Werror -Wall -Wextra

all: co as

co: $(NAME_COR)

as: $(NAME_ASM)

$(NAME_ASM): $(LIBFT) $(OBJ_ASM)
	$(CC) $(CFLAGS) $(OBJ_ASM) $(LIBFT) -Iincludes -o $(NAME_ASM)

$(NAME_COR): $(LIBFT) $(OBJ_COR)
	$(CC) $(CFLAGS) $(OBJ_COR) $(LIBFT) -Iincludes -lncurses -o $(NAME_COR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -Iincludes -o $@

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_COR) $(OBJ_ASM)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME_COR) $(NAME_ASM)
	make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean as cor
