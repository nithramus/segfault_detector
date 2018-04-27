# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bandre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 20:53:12 by bandre            #+#    #+#              #
#    Updated: 2017/03/20 23:38:57 by bandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = libft

SRC_NAME = ft_atoi.c\
		   ft_isdigit.c\
		   ft_memchr.c\
		   ft_memset.c\
		   ft_putendl_fd.c\
		   ft_strcat.c \
		   ft_strdel.c \
		   ft_strjoin.c \
		   ft_strncmp.c\
		   ft_strrchr.c\
		   ft_tolower.c\
		   ft_bzero.c\
		   ft_isprint.c\
		   ft_memcmp.c\
		   ft_putchar.c\
		   ft_putnbr.c\
		   ft_strchr.c\
		   ft_strdup.c\
		   ft_strlen.c\
		   ft_strncpy.c\
		   ft_strsplit.c\
		   ft_toupper.c\
		   ft_isalnum.c\
		   ft_itoa.c\
		   ft_memcpy.c\
		   ft_putchar_fd.c\
		   ft_putnbr_fd.c\
		   ft_strclr.c\
		   ft_strequ.c\
		   ft_strmap.c\
		   ft_strnequ.c\
		   ft_strstr.c\
		   ft_isalpha.c\
		   ft_memalloc.c\
		   ft_memdel.c\
		   ft_putchartab.c\
		   ft_putstr.c\
		   ft_strcmp.c\
		   ft_striter.c\
		   ft_strmapi.c\
		   ft_strnew.c\
		   ft_strsub.c\
		   ft_isascii.c\
		   ft_memccpy.c\
		   ft_memmove.c\
		   ft_putendl.c\
		   ft_putstr_fd.c\
		   ft_strcpy.c\
		   ft_striteri.c\
		   ft_strncat.c\
		   ft_strnstr.c\
		   ft_strtrim.c\
		   ft_strlcat.c\
		   ft_lstnew.c\
		   ft_lstdelone.c\
		   ft_lstdel.c\
		   ft_lstadd.c\
		   ft_lstiter.c\
		   ft_lstmap.c\
		   ft_putlst.c\
		   ft_itoa_base.c\
		   ft_itoa_base_signed.c\
		   get_next_line.c\
		   ft_affichage.c\
		   ft_gestion_flag.c\
		   ft_gestion_precision.c\
		   ft_gestionspe.c\
		   ft_printf.c\
		   ft_unicode.c\
		   ft_cassupp.c\
		   ft_initparam.c\
		   specifier.c\
		   ft_ptradd.c\
		   ft_ptradd_free.c\
		   ft_afficher_tab_c.c\
		   ft_is_number.c\
		   mem_stock.c\
		   mem_stock_free.c\
		   mem_free_ptr.c\


OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

CPPFLAGS = -I.

CC = gcc
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
