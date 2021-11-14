NAME	=	fractol
SRCS	=	srcs/complex.c\
			srcs/fractol.c
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
LIBFT	=	libft/libft.a

all:		$(NAME)
$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) -o $(NAME)
$(LIBFT):
	Make -C libft
%.o: %.c
	$(CC) $(FLAGS) -Ilibft -Iincludes -I/usr/include -Imlx_linux -O3 -c $< -o $@
$(LIBFT):
	make -C libft
clean:
	make fclean -C libft
	rm -f $(OBJS)
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
re: fclean all
