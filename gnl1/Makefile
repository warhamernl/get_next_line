# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mlokhors <mlokhors@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/28 14:33:42 by mlokhors       #+#    #+#                 #
#    Updated: 2020/01/06 06:58:24 by mlokhors      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=gnl

all: $(NAME)


$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -g -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft

clean :
	rm -f main.o get_next_line.o main2.o

fclean : clean
	rm -f $(NAME)

re: fclean all
