# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 08:59:28 by tglaudel          #+#    #+#              #
#    Updated: 2016/05/12 19:32:40 by ale-naou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH_ASM = ./srcs/asm/
SRC_PATH_COR = ./srcs/corewar/
OBJ_PATH_ASM = ./objasm/
OBJ_PATH_COR = ./objcor/

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

SRC_NAME_COR = main.c \
			   op.c \
			   get_opt.c \
			   get_opt_dv.c \
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
			   recup_value.c \
			   live.c \
			   ld.c \
			   st.c \
			   add.c \
			   sub.c \
			   and.c \
			   or.c \
			   xor.c \
			   zjmp.c \
			   ldi.c \
			   lld.c \
			   lldi.c \
			   sti.c \
			   fork.c \
			   lfork.c \
			   aff.c \
			   check_champ_cycle.c \
			   free_all.c \
			   test_opt.c \

OBJ_NAME_ASM = $(SRC_NAME_ASM:.c=.o)
OBJ_NAME_COR = $(SRC_NAME_COR:.c=.o)

SRC_ASM = $(addprefix $(SRC_PATH_ASM), $(SRC_NAME_ASM))
SRC_COR = $(addprefix $(SRC_PATH_COR), $(SRC_NAME_COR))
OBJ_ASM = $(addprefix $(OBJ_PATH_ASM), $(OBJ_NAME_ASM))
OBJ_COR = $(addprefix $(OBJ_PATH_COR), $(OBJ_NAME_COR))

NAME_ASM = asm
NAME_COR = corewar

CC = gcc
LIBFT = libft/libft.a
CFLAGS = -Werror -Wall -Wextra

all: co as

co: $(NAME_COR)
as: $(NAME_ASM)

$(NAME_ASM): $(LIBFT) $(OBJ_ASM)
	$(CC) $(CFLAGS) $(LIBFT) $(SRC_ASM) -Iincludes -o $(NAME_ASM)

$(NAME_COR): $(LIBFT) $(OBJ_COR)
	$(CC) $(CFLAGS) $(LIBFT) $(SRC_COR) -Iincludes -lncurses -o $(NAME_COR)

$(OBJ_PATH_ASM)%.o: $(SRC_PATH_ASM)%.c
	@mkdir $(OBJ_PATH_ASM) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -Iincludes -o $@

$(OBJ_PATH_COR)%.o: $(SRC_PATH_COR)%.c
	@mkdir $(OBJ_PATH_COR) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -Iincludes -o $@

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_PATH_COR) $(OBJ_PATH_ASM)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME_COR) $(NAME_ASM)
	make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean as cor
