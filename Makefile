NAME = push_swap
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = allowed_functions_1.c \
allowed_functions_2.c \
main.c \
radix_sort_core.c \
radix_sort.c \
simple_sort.c \
utils.c \
utils_stack.c \
utils_parse.c


OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
