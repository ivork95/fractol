# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ivork <ivork@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/14 22:58:41 by ivork         #+#    #+#                  #
#    Updated: 2021/11/14 23:05:03 by ivork         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		fractol

SRCS =		srcs/fractol.c srcs/complex.c
INCLUDES =	-Ilibft -Iincludes -Imlx_linux
OBJS =		$(SRCS:.c=.o)
CFLAGS =	-Wall -Werror -Wextra
LIBFT	=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) libmlx.dylib
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) \
	$(LIBFT) mlx_linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(LIBFT):
	make -C libft

libmlx.dylib:
	make -C mlx_linux

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean:
	rm -f $(OBJS) $(NAME)
	make -C libft fclean
	make -C mlx_linux clean

re: fclean all

.PHONY: all clean fclean re mlx libft bonus FORCE