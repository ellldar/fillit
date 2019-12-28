NAME = fillit
SRC = src/fillit.c src/read_ops.c src/tetri_ops.c src/solvers.c src/helpers.c
HDR = -I /includes
LIB = -L./libft -lft
FLG = -Wall -Werror -Wextra
SANIT = -fsanitize=address
INPUT = tests/test1.txt

.PHONY: all debug sanit clean fclean re

all: $(NAME)

$(NAME): $(INPUT)
	@gcc -o $(NAME) $(SRC) $(HDR) $(LIB) $(FLG)
	@./$(NAME) $(INPUT) | cat -e

debug:
	@gcc -o $(NAME) $(SRC) $(HDR) $(LIB) $(FLG) -g
	@lldb $(NAME) -- $(INPUT)

sanit:
	@gcc -o $(NAME) $(SRC) $(HDR) $(LIB) $(FLG) $(SANIT) -g
	@./$(NAME) $(INPUT) | cat -e

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM/

re: fclean all

norm:
	@norminette src/*.c includes/*.h