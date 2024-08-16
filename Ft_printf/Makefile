SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS) ft_printf.h
		   ar rcs $(NAME) $(OBJS)
%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
	
