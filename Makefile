NAME = fillit
SRC = fillit.c helpers.c
HDR = -I.
LIB = -L./libft -lft
FLG = -Wall -Werror -Wextra
SANIT = -fsanitize=address
INPUT = sample.txt

.PHONY: all debug sanit clean fclean re

all: $(NAME)

$(NAME): $(INPUT)
	@gcc -o $(NAME) $(SRC) $(HDR) $(LIB)
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

re: fclean all

norm:
	@norminette *.c *.h libft/*.c libft/*.h