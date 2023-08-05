#include "push_swap.h"

void order_stack_size_3(t_stack *stack)
{
    while(!(stack->data[0] < stack->data[1] && stack->data[1] < stack->data[2]))
    {
        if (stack->data[0] > stack->data[1] && stack->data[0] < stack->data[2])
            sa(stack);
        else if (stack->data[1] > stack->data[0] && stack->data[1] > stack->data[2])
            rra(stack);
        else if (stack->data[0] > stack->data[1] && stack->data[0] > stack->data[2])
            ra(stack);
    }
}

//void order_stack_size_5

void    order_next_num(t_stack *stack_a, t_stack *stack_b)
{
    int cheapest_index;
    int cheapest_ops;
    int ops
    int i;
    
    while (stack_a->size > 3)
    {
        cheapest_index = -1;
        cheapest_ops = 2147483647
        while (i < stack_a->size)
        {
            ops = calculate_operations(stack_a, stack_b, i);

            if 

            i++;
        }
    }
}

void    turk_sort(t_stack *stack_a, t_stack *stack_b)
{
    //int opeartions;

    stack_b->data = NULL;
    //order_next_num
    order_stack_size_3(stack_a);
    //final_rearange()
}