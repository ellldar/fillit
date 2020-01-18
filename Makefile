NAME = fillit
SRC = fillit/fillit.c fillit/read_ops.c fillit/tetri_ops.c fillit/solvers.c fillit/helpers.c
HDR = -I /fillit
LIB = libft
LIBFLG = -L./$(LIB) -lft
FLG = -Wall -Werror -Wextra

.PHONY: all debug sanit clean fclean re libft

all: $(NAME)

$(NAME): $(LIB)
	make -C $(LIB) re
	make -C $(LIB) clean
	gcc -o $(NAME) $(SRC) $(HDR) $(LIBFLG) $(FLG)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM/

re: fclean all

norm:
	@norminette src/*.c includes/*.h