#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser.h"

int is_duplicate(t_stack *stack, int value)
{
    int i;

    i = 0;
    while (i < stack->size)
    {
        if (stack->data[i] == value)
        {
            ft_printf("Error: Duplicate value '%d' detected.\n", value);
            free(stack->data);
            return (1);
        }
        i++;
    }
    return (0);
}

int parse_stack(int argc, char *argv[], t_stack *stack)
{
    int i;

    stack->size = argc - 1;     //Read argc and assigng size to the stack
    stack->data = malloc(stack->size * sizeof(int)); //Allocate memory for it
    if (stack->data == NULL)
    {
        ft_printf("Error: Memory allocation failed.\n");
        return (0);
    }

    i = 1;
    while (i < argc)
    {
        // Parse argument as an integer
        char *end_ptr;
        int value = strtol(argv[i], &endptr, 10); //*************************
        if (*endptr != '\0')
        {
            ft_printf("Error: Argument '%s' is not an integer.\n", argv[i]);
            free(stack->data);
            return (0);
        }

        // Check for duplicate values
        if (is_duplicate(stack, value))
            return (0);

        stack->data[i - 1] = value;
        i++;
    }

    return (1);
}
