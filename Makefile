NAME = fractol

CFLAGS = -Wall -Wextra -Wextra -mtune=native -march=native -Ofast -fsanitize=address -g
INCLUDES =	-Ilibft -Iincludes
FILES =	main fractol complex color window pixel_put
SRC = $(FILES:%=srcs/%.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cd libft/ && $(MAKE)
	gcc  $(CFLAGS) -o $(NAME) $(OBJ) -Iincludes libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit

%.o:%.c
	gcc $(CFLAGS) -Iincludes -Imlx -c -o $@ $<

clean:
	rm -f $(OBJ)
	cd libft/ && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd libft/ && rm -f libft.a

re: fclean all