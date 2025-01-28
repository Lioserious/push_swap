# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 14:13:24 by lihrig            #+#    #+#              #
#    Updated: 2025/01/28 17:25:08 by lihrig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = cc
CC_FLAGS = -Wall -Werror -Wextra

# Targets
PUSHSWAP = push_swap

# Source and Object Files
SRC_FILES = push_swap.c \
			stack_sort.c \
			stack_init.c \
			support_functions.c \
			main.c \
			

OBJ_FILES = $(SRC_FILES:%.c=%.o)

# Paths to Libft and Printf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Default target
all: $(LIBFT) $(PRINTF) $(PUSHSWAP)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CC_FLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

# Rule to create the executables
$(PUSHSWAP): $(OBJ_FILES) $(LIBFT) $(PRINTF)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(PUSHSWAP)

# Build Libft (if not already built)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build Printf (if not already built)
$(PRINTF):
	make -C $(PRINTF_DIR)

# Clean up object files and executables
clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(PUSHSWAP)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
