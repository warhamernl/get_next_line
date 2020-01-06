NAME=gnl
EXTRA=
FLAGS=-Wall -Wextra -Werror $(EXTRA)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang $(FLAGS) -I libft/includes -o get_next_line.o -c get_next_line.c
	clang $(FLAGS) -I libft/includes -o main.o -c main.c
	clang $(FLAGS) -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft

clean :
	rm -f *.o
	make -C libft/ fclean

fclean : clean
	rm -f $(NAME)
	rm -Rf $(NAME).dSYM

re: fclean all

lldb: fclean
	make -C libft/ fclean && make -C libft/
	clang -g -o $(NAME) main.c get_next_line.c -I libft/includes -L libft/ -lft
	lldb gnl bestand
