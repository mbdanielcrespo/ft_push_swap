NAME = push_swap
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = allowed_functions_1.c \
allowed_functions_2.c \
calculate_ops.c \
main.c \
perform_rotations.c \
solver.c \
utils.c \
utils_stack.c \
utils_stack_order.c


OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
