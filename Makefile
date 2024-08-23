#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/23 14:45:13 by shurtado          #+#    #+#              #
#    Updated: 2024/08/23 15:48:43 by shurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config
CC = cc
TARGET = libft.a
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR)

# Folders
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Sources
SRCS_FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c
SRCS_FILES += ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c
SRCS_FILES += ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_FILES += ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstdelone.c
SRCS_FILES += get_next_line.c ft_strfill_fd.c ft_free_2d_array.c
SRCS_FILES += ft_printf/ft_printf.c ft_printf/ft_printf_utils.c ft_printf/ft_printf_utils2.c
SRCS = $(addprefix $(SRC_DIR)/,$(SRCS_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	@ar rcs $(TARGET) $(OBJS)
	@echo "\033[1;36mBinary $@ created\033[0m"

# -MMD to include header dependences to .d file and run $(OBJ_DIR) if not exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -c $< -o $@ > /dev/null
	@echo "\033[0;32mObject $@ created\033[0m"

# Create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/ft_printf

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "\033[1;31mlibft objects deleted\033[0m"; \
	fi


fclean: clean
	@if [ -f "$(TARGET)" ]; then \
		rm -f $(TARGET); \
		echo "\033[1;31m$(TARGET) deleted\033[0m"; \
	fi

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
