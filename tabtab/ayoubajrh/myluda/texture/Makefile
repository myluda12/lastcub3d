NAME = cub3D


MLX_PATH = /usr/local/lib
MLX_LIB = mlx

SRCS = cub3d.c readfile1.c readfile2.c readfile3.c sprite.c raycasting1.c \
		raycasting2.c utils1.c utils2.c error.c render2d.c render3d.c \
		mlx_utils.c textures.c map1.c get_next_line.c get_next_line_utils.c \
		screenshot.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wextra -Wall

ASAN = -g -fsanitize=address

$(NAME) :
	gcc -g $(SRCS) -L $(MLX_PATH) -l$(MLX_LIB) -L  \
	-framework OpenGL -framework AppKit -o $(NAME)
	
all: $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean:
	rm -rf $(NAME) $(OBJS)
	make fclean -C $(LIBFT_PATH)

re: fclean all

bounus: