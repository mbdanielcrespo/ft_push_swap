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

void push_from_index(t_stack *stack_a, t_stack *stack_b, int index)
{
    int r_a;
    int r_b;
	int	r_both;
	int target_index;
	
	target_index = calculate_target_index(stack_a, stack_b, index);
	if (index <= (stack_a->size / 2))
        r_a = index;
    else
        r_a = -(stack_a->size - index);
    if (target_index == stack_b->size)
        r_b = -1;
    else if (target_index <= (stack_b->size / 2))
        r_b = target_index;
    else
        r_b = -(stack_b->size - target_index);
    r_both = calculate_r_both(r_a, r_b);
    perform_rotations_a(stack_a, (r_a - r_both));
	perform_rotations_b(stack_b, (r_b - r_both));
	perform_rotations_both(stack_a, stack_b, r_both);
    pb(stack_a, stack_b);
}

void order_next_num(t_stack *stack_a, t_stack *stack_b)
{
    int min_index;
    int min_ops;
    int ops;
    int i;
	
    while (stack_a->size > 0)
    {
        min_index = -1;
        min_ops = 2147483647;
		i = 0;
        while (i < stack_a->size)
        {
            ops = calculate_ops(stack_a, stack_b, i);
            if (ops < min_ops)
            {
                min_ops = ops;
                min_index = i;
            }
            i++;
        }
        /*
		printf("VALUE TO BE PUSHED ops: %d, min_index: %d, value: %d\n", min_ops, min_index, stack_a->data[min_index]);
		print_stack("A", stack_a);
		print_stack("B", stack_b);
        */
        if (min_index == -1)
            break;
        push_from_index(stack_a, stack_b, min_index);
    }
}