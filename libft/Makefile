# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajesus- <dajesus-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 14:40:17 by dajesus-          #+#    #+#              #
#    Updated: 2024/11/12 02:21:47 by dajesus-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= libft.a
CC      	= cc
CFLAGS 		= -Wall -Wextra -Werror

INCLUDE 	= -I.
SRCS 		= ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
			ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c\
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c\
			ft_strlen.c ft_strncmp.c ft_strrchr.c ft_toupper.c\
			ft_tolower.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_putunsigned_dec_fd.c\
			ft_putunsigned_hex_fd.c ft_numlen_dec.c ft_numlen_hex.c

BONUS_SRCS 	= ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS 		= $(SRCS:%.c=%.o)
OBJS_BONUS 	= $(BONUS_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	@make OBJS="$(OBJS_BONUS)" --no-print-directory

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
