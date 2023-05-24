# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 18:31:22 by inwagner          #+#    #+#              #
#    Updated: 2023/05/23 20:47:19 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAMES
BNAME	:=	checker

# FLAGS
HDR		:=	-I ../../includes/
CFLAG	:=	-Wall -Werror -Wextra

# PATHS
OSRC	:=	../../objs/
BSRC	:=	../../
GSRC	:=	./gnl/
BPATH	:=	$(addprefix ${BSRC}, ${BNAME})

# BONUS
BFTS	:=	checker_bonus.c \
			utils_list_bonus.c \
			utils_bonus.c \
			parse_bonus.c \
			swap_bonus.c \
			push_bonus.c \
			rotate_bonus.c \
			reverse_rotate_bonus.c
BOBJ	:=	$(BFTS:%.c=$(OSRC)%.o)

# GNL
GFTS	:=	get_next_line.c \
			get_next_line_utils.c
GOBJ	:=	$(GFTS:%.c=$(OSRC)%.o)

# Commands
all: $(BPATH)

# Compile objects
$(BPATH): $(GOBJ) $(BOBJ)
	cc $(CFLAG) $(GOBJ) $(BOBJ) -o $@

# Make Objects
$(OSRC)%.o: $(GSRC)%.c
	mkdir -p $(OSRC)
	cc $(CFLAG) $(HDR) -c $< -o $@

$(OSRC)%.o: %.c
	mkdir -p $(OSRC)
	cc $(CFLAG) $(HDR) -c $< -o $@

# Cleaners e Remaker
clean:
	@[ -d $(OSRC) ] && rm -rf $(OSRC) && echo objects deleted || [ -f Makefile ]

fclean: clean
	@[ -f $(BPATH) ] && rm $(BPATH) && echo $(BNAME) deleted || [ -f Makefile ]
	
re: fclean all

# Recipes
.PHONY: all clean fclean re