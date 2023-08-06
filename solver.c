#include "push_swap.h"

int ft_min(int a, int b)
{
    if (b < a)
        return (b);
    else
    	return (a);
}

int	ft_abs(int a)
	if (a < 0)
		return (a * -1);
	else
		return (a);

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

int	calculate_target_index(t_stack *stack_a, t_stack *stack_b, int index)
{
	int element_to_move;
	int	current;
    int target_index;
	int	i;
	
	element_to_move = stack_a->data[index];
	target_index = -1;
	i = 0;
	while (i < stack->size - 1)
	{
		current = stack_b->data[i];
		if (element_to_move < current)
		{
			target_index = i;
		}
		i++;
	}
	if (target_index == -1)
		target_index = stack_b->size;
	return (target_index);
}

int calculate_ops_for_target_index(t_stack *opposite_stack, int target_index) {
    int regular_rotations;
    int reverse_rotations;
    int min_rotations;

	regular_rotations = target_index;
	reverse_rotations = opposite_stack->size; - target_index;
	if (regular_rotations < reverse_rotations)
		min_rotations = regular_rotations;
	else
		min_rotations = -reverse_rotations;
    return min_rotations;
}

int	calculate_ops(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	r_a;
	int	r_b;
	int	r_both;
	int	min_ops;
	int	target_index;

	r_a = index;
	if (index >= stack_b->size) 
    	r_b = index % stack_b->size;
	else
		r_b = index;
	r_both = ft_min(ft_abs(r_a), ft_abs(r_b));
	target_index = calculate_target_index(stack_a, stack_b, i);
	min_ops = r_both + ft_abs(calculate_ops_for_target_index(stack_b, target_index));
	return (min_ops);
}

// falta fazer o algoritmo mais eficente peruntar a logica ao chatgpt

void order_next_num(t_stack *stack_a, t_stack *stack_b)
{
    int min_index;
    int min_ops;
    int ops;
    int i;
	
	i = 0;
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
        if (min_index == -1)
            break;
        pb_from_index(stack_a, stack_b, min_index);
    }
}

void    turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
    order_next_num(stack_a, stack_b);
}




/*I've done the corrections but the code, I am not sure if its working properly, check if these are the supposed results fr this two cases:
Stacks status before sorting: (a) 1 2 3 4 5 6 7 8 10 9 
Stacks status after sorting: (b) 9 10 8 7 6 5 4 3 2 1

Stacks status before sorting: (a) 1 7 2 14 5 11 3 8 9 10
Stacks status after sorting: (b) 10 9 8 3 11 5 14 2 7 1 */