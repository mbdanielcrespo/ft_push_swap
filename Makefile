NAME = push_swap
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src/actions.c \
src/allowed_functions_1.c \
src/allowed_functions_2.c \
src/main.c \
src/radix_sort_core.c \
src/radix_sort.c \
src/simple_sort.c \

UTILS = utils/utils.c \
utils/utils_stack.c \
utils/utils_parse.c


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
