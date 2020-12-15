# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kplums <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 21:26:53 by kplums            #+#    #+#              #
#    Updated: 2020/01/22 21:26:57 by kplums           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_DIR = ./src/
LIB_DIR = ./libft/
OBJ_DIR = ./obj/
SRC_INC_DIR = ./includes/
LIB_INC_DIR = ./libft/includes/

CFLGS = -Wall -Werror -Wextra
LFLGS = -L$(LIB_DIR) -lft
CC = gcc

LIBFT = $(LIB_DIR)/libft.a

SRC_FILES = fillit.c ft_sizemat.c main.c ft_validfile.c ft_work_fi.c ft_ittet.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

INCL = -I$(SRC_INC_DIR) -I$(LIB_INC_DIR)

.PHONY: all clean fclean re

all: $(NAME)

-include: $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) -c -o $@ $< $(INCL)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLGS) -o $(NAME) $(OBJS) $(INCL) $(LFLGS)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
