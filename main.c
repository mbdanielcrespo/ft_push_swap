#include "push_swap.h"

int ft_mod_atoi(const char *str, int *value) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] != '\0') 
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        result = result * 10 + (str[i] - '0');
        if ((sign == 1 && result > 2147483647) || (sign == -1 && result < -2147483648))
            return (0);
        i++;
    }

    *value = result * sign;
    return (1);
}

void turk_sort(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 3)
        order_stack_size_3(stack_a);
    else
    {
        while (!is_circularly_sorted(stack_a))
        {
            pb(stack_a, stack_b);
            pb(stack_a, stack_b);
            order_next_num(stack_a, stack_b);

            pa(stack_a, stack_b);
            pa(stack_a, stack_b);
            order_next_num(stack_b, stack_a);
        }
        perform_rotations_a(stack_a, -rotations_to_sort(stack_a));
    }
}

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    int value;
    int i;

    if (argc < 2)
    {
        printf("List of integrers: %s\n", argv[0]);
        return (0);
    }
    init_stack(&stack_a, argc - 1);
    init_stack(&stack_b, argc - 1);
    printf("--------------------- Stacks status before parsing\n");
    print_stack("A", &stack_a);
    print_stack("B", &stack_b);
    printf("\n");
    
    i = 1;
    while (i < argc) 
    {
        if (!ft_mod_atoi(argv[i], &value)) 
        {
            printf("Error: Invalid argument '%s'\n", argv[i]);
            free_stack(&stack_a);
            return (0);
        }
        stack_a.data[stack_a.size++] = value;
        i++;
    }
    printf("--------------------- Stacks status before sorting\n");
    print_stack("A", &stack_a);
    print_stack("B", &stack_b);
    printf("\n");
    
    turk_sort(&stack_a, &stack_b);

    printf("--------------------- Stacks status after sorting\n");
    print_stack("A", &stack_a);
    print_stack("B", &stack_b);
    printf("\n");
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}