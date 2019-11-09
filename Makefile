NAME = fillit
SRC = fillit.c
HDR = -I.
LIB = -L/libft -lft
FLG = -Wall -Werror -Wextra
SANIT = 
INPUT = example.txt
all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(HDR) $(LIB) $(FLG)
	./$(NAME) $(INPUT) | cat -e

debug:
	gcc -o $(NAME) $(SRC) $(HDR) $(LIB) $(FLG) -g
	lldb $(NAME) -- $(INPUT)

sanit:
	gcc -o $(NAME) $(SRC) $(HDR) $(LIB) $(FLG) --fsanitize=address -g
	./$(NAME) $(INPUT) | cat -e

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette *.c *.h libft/*.c libft/*.h
