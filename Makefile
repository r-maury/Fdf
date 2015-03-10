# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:47:23 by rmaury            #+#    #+#              #
#    Updated: 2015/02/19 19:10:51 by rmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CCLIB = -Llibft -lft -L/usr/X11/lib -lmlx -lXext -lX11
CCFLAGS = -Wall -Werror -Wextra
SRCDIR = src
OBJDIR = obj
INCDIR = libft

SRC +=    main_fdf.c
SRC +=    draw_line.c
SRC +=    fdf_error.c
SRC +=    display_map.c
SRC +=    gnl_counter.c
SRC +=    hooks.c
SRC +=    readmap.c
SRC +=    get_next_line.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C libft
	@gcc $(CCLIB) -o $(NAME) -I /usr/X11/include/X11/x.h $(OBJS)
build:
	@mkdir -p $(OBJDIR)
clean:
	@make -C libft clean
	@rm -f $(OBJS)
fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -rf obj
re: fclean all

dev : all
	@./$(NAME)

.PHONY: clean fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c -g $(CCFLAGS) $(INCS) -I includes/ -o $@ $<
