NAME = validate
SRC = main.c helpers.c
HDR = -I.
LIB = -L../libft -lft
FLG = -Wall -Werror -Wextra
SANIT = --fsanitize=address
INPUT = test1.txt

.PHONY: all validate debug sanit test clean

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRC) $(HDR) $(LIB)
	@./$(NAME) $(INPUT) | cat -e

debug:
	@gcc -o $(NAME) $(SRC) $(HDR) $(LIB) -g
	@lldb $(NAME) -- $(INPUT)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all