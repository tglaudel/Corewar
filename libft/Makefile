# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 14:29:20 by tglaudel          #+#    #+#              #
#    Updated: 2016/03/22 17:21:48 by tglaudel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PRINTF = printf

SRC_LIB = libft

SRC_GNL = gnl

SRC_LIB_NAME = ft_memset.c ft_memalloc.c ft_lstnew.c \
		   ft_bzero.c ft_memdel.c ft_lstdelone.c \
		   ft_memcpy.c ft_strnew.c ft_lstdel.c \
		   ft_memccpy.c ft_strdel.c ft_lstadd.c \
		   ft_memmove.c ft_strclr.c ft_lstiter.c \
		   ft_memchr.c ft_striter.c ft_lstmap.c \
		   ft_memcmp.c ft_striteri.c ft_power.c \
		   ft_strlen.c ft_strmap.c ft_lstaddback.c \
		   ft_strdup.c ft_strmapi.c ft_count_word.c \
		   ft_strcpy.c ft_strequ.c ft_lenword.c \
		   ft_strncpy.c ft_strnequ.c ft_sqrtlow.c \
		   ft_strcat.c ft_strsub.c ft_putstr_color.c \
		   ft_strncat.c ft_strjoin.c ft_itoa_base.c \
		   ft_strlcat.c ft_strtrim.c ft_atod.c\
		   ft_strchr.c ft_strsplit.c ft_isupper.c \
		   ft_strrchr.c ft_itoa.c ft_errors.c \
		   ft_strstr.c ft_putchar.c ft_mystrsplit.c \
		   ft_strnstr.c ft_putstr.c \
		   ft_strcmp.c ft_putendl.c \
		   ft_strncmp.c ft_putnbr.c \
		   ft_atoi.c ft_putchar_fd.c \
		   ft_isalpha.c ft_putstr_fd.c \
		   ft_isdigit.c ft_putendl_fd.c\
		   ft_isalnum.c ft_putnbr_fd.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_toupper.c \
		   ft_tolower.c \

SRC_PRINTF_NAME = ft_printf.c \
				  ft_def.c \
				  ft_istype.c \
				  print_num.c \
				  print_string.c \
				  utils.c \
				  print_char.c \
				  print_ptr.c \

SRC_GNL_NAME = get_next_line.c \

SRC_PATH_PF = $(addprefix $(SRC_PRINTF)/,$(SRC_PRINTF_NAME))

SRC_PATH_LIB = $(addprefix $(SRC_LIB)/,$(SRC_LIB_NAME))

SRC_PATH_GNL = $(addprefix $(SRC_GNL)/,$(SRC_GNL_NAME))

OBJ_LIB = $(SRC_LIB_NAME:.c=.o)

OBJ_PRINTF = $(SRC_PRINTF_NAME:.c=.o)

OBJ_GNL = $(SRC_GNL_NAME:.c=.o)

NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC_PATH_LIB) -I ./includes
	@$(CC) $(CFLAGS) -c $(SRC_PATH_PF) -I ./includes
	@$(CC) $(CFLAGS) -c $(SRC_PATH_GNL) -I ./includes
	@ar rc $(NAME) $(OBJ_LIB) $(OBJ_PRINTF) $(OBJ_GNL)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_LIB)
	@rm -rf $(OBJ_PRINTF)
	@rm -rf $(OBJ_GNL)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean
