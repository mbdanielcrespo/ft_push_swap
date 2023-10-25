NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = gcc

SRC = src/actions.c \
src/allowed_functions_1.c \
src/allowed_functions_2.c \
src/main.c \
src/radix_sort.c \
src/simple_sort.c \

UTILS = utils/utils.c \
utils/utils_stack.c \
utils/utils_parse.c \
utils/t_list.c

OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)

LIBFT = libft/ft_libft.a

all: $(NAME)


$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft -lft

$(LIBFT):
	make -C libft
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	cd libft && make clean
	rm -f $(OBJ)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
