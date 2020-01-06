# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mlokhors <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/22 11:58:38 by mlokhors      #+#    #+#                  #
#    Updated: 2019/04/28 16:50:06 by mlokhors      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

OBJECT_NAMES=ft_memcpy \
			 ft_memset \
			 ft_memmove \
			 ft_bzero \
			 ft_memccpy \
			 ft_memchr \
			 ft_memcmp \
			 ft_strlen \
			 ft_strdup \
			 ft_strcpy \
			 ft_strncpy \
			 ft_strcat \
			 ft_strncat \
			 ft_strlcat \
			 ft_strchr \
			 ft_strrchr \
			 ft_strstr \
			 ft_strnstr \
			 ft_strcmp \
			 ft_strncmp \
			 ft_atoi \
			 ft_isalpha \
			 ft_isdigit \
			 ft_isalnum \
			 ft_isascii \
			 ft_isprint \
			 ft_toupper \
			 ft_tolower \
			 ft_memalloc \
			 ft_memdel \
			 ft_strnew \
			 ft_strdel \
			 ft_strclr \
			 ft_striter \
			 ft_striteri \
			 ft_strmap \
			 ft_strmapi \
			 ft_strequ \
			 ft_strnequ \
			 ft_strsub \
			 ft_strjoin \
			 ft_strtrim \
			 ft_itoa \
			 ft_strsplit \
			 ft_putchar \
			 ft_putstr \
			 ft_putendl \
			 ft_putnbr \
			 ft_putchar_fd \
			 ft_putstr_fd \
			 ft_putendl_fd \
			 ft_putnbr_fd \
			 ft_isspace \
			 ft_lstnew \
			 ft_lstdelone \
			 ft_lstdel \
			 ft_lstadd \
			 ft_lstiter \
			 ft_lstmap \
			 ft_countwords \
			 ft_strrev \
			 ft_itoa_base \
			 ft_iswhitespace \


NAME=libft.a
CC=gcc
FLAGS=-Werror -Wextra -Wall -I./includes
OBJ=$(patsubst %, %.o, $(OBJECT_NAMES))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Making library"
	@ar rc $@ $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@echo "Making object $@"
	@$(CC) -c -o $@ $^ $(FLAGS)

clean:
	@echo Cleaning objects
	@rm -f $(OBJ)

fclean: clean
	@echo Cleaning libft
	@rm -f $(NAME)



re: fclean all
