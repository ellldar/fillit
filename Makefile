NAME = fillit
SRC = project/fillit.c project/read_ops.c project/tetri_ops.c project/solvers.c project/helpers.c
HDR = -I /project
LIB = libft
LIBFLG = -L./$(LIB) -lft
FLG = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB)
	make -C $(LIB)
	gcc -o $(NAME) $(SRC) $(HDR) $(LIBFLG) $(FLG)

clean:
	make -C $(LIB) clean

fclean: clean
	make -C $(LIB) fclean
	rm -f $(NAME)

re: fclean all

norm:
	@norminette src/*.c includes/*.h