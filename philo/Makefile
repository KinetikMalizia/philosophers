# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 13:51:43 by fmalizia          #+#    #+#              #
#    Updated: 2022/06/30 12:58:53 by fmalizia         ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

SRC_DIR := srcs
OBJ_DIR := objs
BIN_DIR := .

NAME := philo
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS := -Wall -Werror -Wextra -g

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m



all:start $(NAME)

start:
	@tput setaf 6; cat includes/art; tput setaf default
	@printf "$(CY) **Compiling Philosophers**\n$(RE)"

rules:
	@printf "$(CY)**USE: ./philosophers <number of philosophers> <time to die> <time to eat> <time to sleep> (optional)<number of times each philosophers must eat>\n$(RE)"

$(NAME): $(OBJ) | $(BIN_DIR) 
	@$(CC) $^ -o $@
	@printf "$(GR)SUCCESS$(RC)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GR)///$(RC)"

$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(YE)** Deleting Objects **\n$(RC)"

fclean: clean
	@$(RM) -r $(NAME)
	@printf "$(YE)** Deleting Binary  **\n$(RC)"

re: fclean all

.PHONY: all clean fclean start rules