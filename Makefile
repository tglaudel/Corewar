# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 08:59:28 by tglaudel          #+#    #+#              #
#    Updated: 2016/03/28 14:00:30 by tglaudel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs

SRC_NAME = main.c \
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

OBJ = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

NAME = asm

CC = gcc

LIBFT = libft/libft.a

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Iincludes -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -Iincludes -o $@

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all re clean fclean
