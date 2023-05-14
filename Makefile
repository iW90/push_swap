# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 15:42:23 by inwagner          #+#    #+#              #
#    Updated: 2023/05/14 17:58:03 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAMES
NAME	:=	push_swap
BNAME	:=	push_swap_bonus
PRINTF	:=	ft_printf.a

# FLAGS
HDR		:=	-I ./includes/
CFLAG	:=	-Wall -Werror -Wextra

# PATHS
SRC		:=	./srcs/
OSRC	:=	./objs/
BSRC	:=	./srcs/bonus/
PSRC	:=	./ft_printf/
MOV		:=	moves/

# PRINTF
PTF		:=	$(addprefix ${PSRC}, ${PRINTF})

# MANDATORY
FTS		:=	push_swap.c \
			utils.c \
			utils_list.c \
			parse.c swap.c \
			push.c rotate.c \
			reverse_rotate.c
OBJ		:=	$(FTS:%.c=$(OSRC)%.o)

# BONUS
BFTS	:=	push_swap.c \
			utils.c \
			utils_list.c \
			parse.c swap.c \
			push.c rotate.c \
			reverse_rotate.c
BOBJ	:=	$(BFTS:%.c=$(OSRC)%.o)

# Commands
all: $(NAME)

# Compile objects
$(NAME): $(PTF) $(OBJ)
	cc $(CFLAG) $(OBJ) $(PTF) -o $@
	
bonus: $(PTF) $(BOBJ)
	cc $(CFLAG) $(BOBJ) $(PTF) -o $(BNAME)

# Compile ft_printf
$(PTF):
	$(MAKE) -C $(PSRC) --silent

# Make Objects
$(OSRC)%.o: $(SRC)%.c
	mkdir -p objs
	cc $(CFLAG) $(HDR) -c $< -o $@

$(OSRC)%.o: $(BSRC)%.c
	mkdir -p objs
	cc $(CFLAG) $(HDR) -c $< -o $@

# Cleaners e Remaker
clean:
	@$(MAKE) -C $(PSRC) clean --silent
	@[ -d $(OSRC) ] && rm -rf $(OSRC) && echo objects deleted || [ -f Makefile ]

fclean: clean
	@$(MAKE) -C $(PSRC) fclean --silent
	@[ -f ./$(NAME) ] && rm $(NAME) && echo $(NAME) deleted || [ -f Makefile ]
	@[ -f ./$(BNAME) ] && rm $(BNAME) && echo $(BNAME) deleted || [ -f Makefile ]
	
re: fclean all

# Recipes
.PHONY: all bonus clean fclean re