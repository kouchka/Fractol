# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 16:48:55 by allallem          #+#    #+#              #
#    Updated: 2018/03/08 16:57:15 by allallem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

SRCDIR = Srcs/

OBJDIR = Obj/

HEADER = Includes/

SRC		= main.c\
 				ft_trace.c\
				ft_error.c\
				ft_game.c\
				my_keys_event.c\
				ft_retrace.c\
				ft_thread.c\
				ft_trace_julia.c\
				ft_trace_my_bonus.c\
				ft_my_key_event2.c\
				ft_bonus.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

CC		=	gcc

CFLAGS	=	-Werror -Wextra -Wall -I $(HEADER)

DEL		=	rm -f

LIBX 	= -L minilibx_macos -lmlx -framework OpenGL -framework appkit -lpthread

LIB		= -L libft -lft

all: init $(NAME)

init:
	@mkdir -p $(OBJDIR)

view:
	@echo $(OBJ)
	echo $(SRCS)
	@echo $(SRC)

norm:
	norminette $(SRCDIR) $(HEADER)

re:fclean all

$(NAME):$(OBJ)
	make -C libft
	make -C minilibx_macos
	$(CC) -o $(NAME) $^ $(CFLAGS) $(LIB) $(LIBX)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $^ -o $@

fclean:clean
	make -C libft fclean
	make -C minilibx_macos clean
	@$(DEL) $(NAME)

clean:
	@$(DEL) $(OBJ)
