# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 15:42:23 by inwagner          #+#    #+#              #
#    Updated: 2023/05/23 21:06:54 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAMES
NAME	:=	push_swap
BNAME	:=	checker

# FLAGS
HDR		:=	-I ./includes/
CFLAG	:=	-Wall -Werror -Wextra

# PATHS
SRC		:=	./srcs/
OSRC	:=	./objs/
BSRC	:=	./srcs/bonus/

# MANDATORY
FTS		:=	main.c \
			utils.c \
			utils_list.c \
			parse.c \
			swap.c \
			push.c \
			rotate.c \
			reverse_rotate.c \
			quick_sort.c \
			mini_push_swap.c \
			push_swap.c \
			sort_checkers.c \
			cost_calculator.c
OBJ		:=	$(FTS:%.c=$(OSRC)%.o)

# Commands
all: $(NAME)

# Compile objects
$(NAME): $(OBJ)
	@cc $(CFLAG) $(OBJ) -o $@
	
bonus:
	@$(MAKE) -C $(BSRC) --silent

# Make Objects
$(OSRC)%.o: $(SRC)%.c
	@mkdir -p objs
	@cc $(CFLAG) $(HDR) -c $< -o $@

# Cleaners e Remaker
clean:
	@[ -d $(OSRC) ] && rm -rf $(OSRC) && echo objects deleted || [ -f Makefile ]

fclean: clean
	@$(MAKE) -C $(BSRC) fclean --silent
	@[ -f ./$(NAME) ] && rm $(NAME) && echo $(NAME) deleted || [ -f Makefile ]
	
re: fclean all

# Recipes
.PHONY: all bonus clean fclean re