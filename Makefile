CC = cc
CFLAGS = -Wall -Wextra -Werror -lmlx  -framework OpenGL -framework AppKit
NAME = fractol
SRC=fractol.c mandelbrot.c mouse_control.c\
	utils/ft_putstr_fd.c utils/ft_strncmp.c utils/error.c
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o:%.c fractol.h
	$(CC) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean:clean
	rm -rf $(NAME)
re:fclean all