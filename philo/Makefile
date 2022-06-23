# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 13:51:43 by fmalizia          #+#    #+#              #
#    Updated: 2022/06/23 15:35:41 by fmalizia         ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

SRC_DIR := srcs
OBJ_DIR := objs
BIN_DIR := .

NAME := philosophers
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall -Werror -Wextra

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

.PHONY: all clean

all: start $(NAME)

start:
	@printf "$(CY) **Compiling Philosophers**\n$(RE)"

$(NAME): $(OBJ) | $(BIN_DIR)
	@$(CC) $^ -o $@
	@printf "$(GR)SUCCESS$(RC)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@printf "$(GR)///$(RC)"

$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(YE)** Deleting Objects **\n$(RC)"

fclean: clean
	@$(RM) -r $(NAME)
	@printf "$(YE)** Deleting Binary  **\n$(RC)"

-include $(OBJ:.o=.d)
