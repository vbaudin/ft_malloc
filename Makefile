# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudin <vbaudin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/22 14:35:47 by vbaudin           #+#    #+#              #
#    Updated: 2018/03/15 18:56:08 by vbaudin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_malloc

FLAGS = -Wall -Wextra -Werror
CC = clang -g  -fsanitize=address $(FLAGS)
SRCS_PATH = srcs
OBJS_PATH = objs
BIN_PATH = bin

FILES = main.c \
				ft_malloc.c

SRCS = $(addprefix $(SRCS_PATH)/,$(FILES))
OBJS = $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)
INCLUDE = includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(BIN_PATH)
	$(CC) $^ -o $(BIN_PATH)/$@

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) -o $@ -c $< $(ALL_INCLUDE)

clean:
	rm -rf $(OBJS_PATH)

fclean: clean
	rm -rf $(BIN_PATH)

re: fclean all

git:
	git add -u; git commit -m "Auto Save Push"; git push
