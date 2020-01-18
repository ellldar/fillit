NAME = fillit
SRC = src/fillit.c src/read_ops.c src/tetri_ops.c src/solvers.c src/helpers.c
HDR = -I /includes
LIB = libft
LIBFLG = -L./$(LIB) -lft
FLG = -Wall -Werror -Wextra
SANIT = -fsanitize=address

.PHONY: all debug sanit clean fclean re libft

all: $(NAME)

$(NAME): $(LIB)
	@gcc -o $(NAME) $(SRC) $(HDR) $(LIBFLG) $(FLG)

$(LIB):
	git submodule update --init
	git submodule update --remote
	make -C $(LIB) re
	make -C $(LIB) clean

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM/

re: fclean all

norm:
	@norminette src/*.c includes/*.h