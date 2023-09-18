NAME = cub3d

SRC =   srcs/main.c\
		srcs/get_map.c\
		srcs/error.c\
		srcs/string.c\

CC =	gcc

OBJS = $(SRC:.c=.o)

CFLAGS =	-Werror -Wextra -Wall #-g3 -fsanitize=address

MAKE = make

#LIB2 =	libft/libft.a

INCLUDES = incs/cub3d.h

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIB2)
	$(CC) $(CFLAGS) $(OBJS) $(LIB2) -o $(NAME)
# -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIB2) -o $(NAME)

$(LIB2): libft/*.c
	$(MAKE) -C libft/
	$(MAKE) -C libft/ bonus

all: $(NAME)

clean:
	$(MAKE) -C libft/ clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIB2)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re