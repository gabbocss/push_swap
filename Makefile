# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 10:09:46 by inbauman          #+#    #+#              #
#    Updated: 2025/02/19 16:00:24 by inbauman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
EXECUTABLE = pushito

SRC_DIRS = . libft
INC_DIRS = . libft

vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)

LIB_OBJECTS = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_memset.o ft_strlen.o ft_bzero.o ft_memcpy.o ft_memmove.o \
ft_strlcpy.o ft_toupper.o ft_strlcat.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_atoi.o ft_strnstr.o ft_calloc.o \
ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_split.o \
get_next_line.o ft_printf.o ft_printf_funciones.o control.o push_swap.o memoria.o ft_atoi2.o ft_atoi3.o y_ahora_si_push_swap.o movimientos_s.o movimientos_p.o movimientos_r.o \
control_minimo.o control_0_1.o control_minimo.o movimientos_rr.o posicionamiento.o posicionamiento_min.o posicionamiento_max.o posicionamiento_2.o

CC = gcc
CFLAGS = -I. -Ilibft

all: $(NAME) $(EXECUTABLE) clean

$(LIB_OBJECTS): %.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_OBJECTS)
	ar rcs $(NAME) $(LIB_OBJECTS)

$(EXECUTABLE): push_swap.o $(NAME)
	$(CC) $(CFLAGS) push_swap.o -L. -lft -o $(EXECUTABLE)

push_swap.o: push_swap.c
	$(CC) $(CFLAGS) -c push_swap.c -o push_swap.o

clean:
	rm -f $(LIB_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

