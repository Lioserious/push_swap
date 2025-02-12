# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 14:13:24 by lihrig            #+#    #+#              #
#    Updated: 2025/02/04 17:05:13 by lihrig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = cc
CC_FLAGS = -Wall -Werror -Wextra

# Targets
PUSHSWAP = push_swap

# Source and Object Files
SRC_FILES = error_handling.c \
			input_processing.c \
			input_validation.c \
			support_functions.c \
			k_sort_support.c \
			k_sort.c \
			list_operations_basic.c \
			main.c \
			normalise.c \
			pre_sort.c \
			push_swap_split.c \
			stack_sort.c \
			stack_sort_2.c \

			

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
