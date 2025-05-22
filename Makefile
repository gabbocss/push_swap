# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 10:09:46 by inbauman          #+#    #+#              #
#    Updated: 2025/05/15 19:20:35 by inbauman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
EXECUTABLE = push_swap

SRC_DIRS = . libft
INC_DIRS = . libft
OBJ_DIR = build

vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)

SRC_FILES = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_memset ft_strlen ft_bzero ft_memcpy ft_memmove \
ft_strlcpy ft_toupper ft_strlcat ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_atoi ft_strnstr ft_calloc \
ft_strdup ft_substr ft_strjoin ft_strtrim ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
ft_split get_next_line ft_printf ft_printf_funciones control push_swap memoria ft_atoi2 ft_atoi3 y_ahora_si_push_swap \
movimientos_s movimientos_p movimientos_r control_minimo movimientos_rr inicializar_conteo borrar_impresion control_limites  nuevo_ps_0 \
nuevo_ps_1 quick_sort


LIB_OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

CC = gcc
CFLAGS = -g -I. -Ilibft

all: $(OBJ_DIR) $(NAME) $(EXECUTABLE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_OBJECTS)
	ar rcs $(NAME) $(LIB_OBJECTS)

$(EXECUTABLE): $(OBJ_DIR)/push_swap.o $(NAME)
	$(CC) $(CFLAGS) $(OBJ_DIR)/push_swap.o -L. -lft -o $(EXECUTABLE)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re


