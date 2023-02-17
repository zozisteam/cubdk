# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mraspors <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 22:56:17 by mraspors          #+#    #+#              #
#    Updated: 2023/02/16 22:33:12 by mraspors         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

FILES =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_substr.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_split.c\
		ft_printf.c ft_print_char.c ft_print_hex.c ft_print_number.c\
		ft_print_pointer.c ft_print_string.c ft_print_uint.c\
		get_next_line.c get_next_line_utils.c ft_strcat.c ft_strstr.c\
		ft_strcmp.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c

OBJECTS =	$(FILES:.c=.o)

HEADERS = libft.h 

FLAGS = -Wall -Werror -Wextra

CC = gcc -c

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc libft.a $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f  $(NAME)

re: fclean all
