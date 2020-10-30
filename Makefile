# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrow <marrow@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 18:25:26 by marrow            #+#    #+#              #
#    Updated: 2020/10/30 16:34:30 by marrow           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

CC = gcc
FLAGS =-Wall -Wextra -Werror -O3

INCLUDES = -I$(H_DIR) -I$(LIBFT_H)
OBJ_DIR = objects/

# LIBFT

LIB = -lft -L$(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_H = $(LIBFT_DIR)includes/

# HEADERS

H_CH = checker.h
HEADER_CH = $(addprefix $(H_DIR), $(H_CH))
H_PS = push_swap.h
HEADER_PS = $(addprefix $(H_DIR), $(H_CH))
H_DIR = ./includes/

# PROGRAM CHECKER

DIR_CH = ./sources/checker/
SRC_CH = init.c \
	instruction.c \
	main.c \
	pa_and_pb.c \
	print_stack.c \
	push_swap_error.c \
	push_swap_free.c \
	ra_and_rb.c \
	rra_rrb_rrr.c \
	sa_and_sb.c \
	sorted.c \
	stack_functions.c \
	valid.c
SOURCES_CH = $(addprefix $(DIR_CH), $(SRC_CH))

OBJ_DIR_CH = objects/checker/
OBJ_CH = $(patsubst %.c, %.o, $(SRC_CH))
OBJECTS_CH = $(addprefix $(OBJ_DIR_CH), $(OBJ_CH))

# PROGRAM PUSH_SWAP

DIR_PS = ./sources/push_swap/
SRC_PS = init.c \
	main.c \
	pa_and_pb.c \
	push_swap.c \
	push_swap_error.c \
	push_swap_free.c \
	ra_and_rb.c \
	rra_rrb_rrr.c \
	sa_and_sb.c \
	sort.c \
	sort_big.c \
	sort_hundred.c \
	sort_small_cases.c \
	stack_functions.c \
	stack_len.c \
	tools_alg.c \
	tools_big.c \
	valid.c
SOURCES_PS = $(addprefix $(DIR_PS), $(SRC_PS))

OBJ_DIR_PS = objects/push_swap/
OBJ_PS = $(patsubst %.c, %.o, $(SRC_PS))
OBJECTS_PS = $(addprefix $(OBJ_DIR_PS), $(OBJ_PS))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(LIBFT) $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(LIBFT) $(OBJ_DIR) $(OBJ_DIR_PS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(LIB) $(INCLUDES) $(OBJECTS_PS) -o $(NAME_PS)
	@echo "\n$(NAME_PS): $(GREEN)$(NAME_PS) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_PS) was created$(RESET)"

$(NAME_CH): $(LIBFT) $(OBJ_DIR_CH) $(OBJECTS_CH)
	@$(CC) $(FLAGS) $(LIB) $(INCLUDES) $(OBJECTS_CH) -o $(NAME_CH)
	@echo "\n$(NAME_CH): $(GREEN)$(NAME_CH) object files were created$(RESET)"
	@echo "$(NAME_CH): $(GREEN)$(NAME_CH) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR_CH)
	@mkdir -p $(OBJ_DIR_PS)
	@echo "$(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR_PS)%.o : $(DIR_PS)%.c $(HEADER_PS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(OBJ_DIR_CH)%.o : $(DIR_CH)%.c $(HEADER_CH)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME_PS)
	@echo "$(RED)$(NAME_PS) was deleted$(RESET)"
	@rm -f $(NAME_CH)
	@echo "$(RED)$(NAME_CH) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
