NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDE     = -Ilibft -I.

LIBFT_DIR  	= ./libft

SRCS        = ft_printf.c specifiers.c str_wrappers.c\
			  num_wrappers.c hex_wrappers.c ptr_wrappers.c\
			  errors.c
OBJS        = $(SRCS:%.c=%.o)

all: libft $(NAME)

libft:
	make -C libft --no-print-directory

$(NAME): $(OBJS)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
