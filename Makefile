NAME = fractol

CFLAGS = -Wall -Wextra -mtune=native -march=native -Ofast
INCLUDES =	-Ilibft -Iincludes
FILES =	main fractol complex color window
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