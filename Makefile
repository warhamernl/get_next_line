# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mlokhors <mlokhors@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/28 14:33:42 by mlokhors       #+#    #+#                 #
#    Updated: 2019/04/28 14:50:39 by mlokhors      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=gnl

all: $(NAME)


$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft

emire:
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o emimain.o -c emimain.c
	clang -o $(NAME) emimain.o get_next_line.o -I libft/includes -L libft/ -lft

clean :
	rm -f main.o get_next_line.o emimain.o

fclean : clean
	rm -f $(NAME)

re: fclean all