#include "push_swap.h"

void find_closest_numbers(t_stack *stack_b, int element_to_move, int *closest_below, int *closest_above) 
{
    int i;

    i = 0;
    *closest_below = INT_MIN; // Smallest number in stack_b that's below element_to_move
    *closest_above = INT_MAX; // Largest number in stack_b that's above element_to_move

    while (i < stack_b->size) 
    {
        if (stack_b->data[i] < element_to_move && stack_b->data[i] > *closest_below)
            *closest_below = stack_b->data[i];
        else if (stack_b->data[i] > element_to_move && stack_b->data[i] < *closest_above)
            *closest_above = stack_b->data[i];
        i++;
    }
}

int calculate_target_index(t_stack *stack_a, t_stack *stack_b, int index) {
    int element_to_move = stack_a->data[index];
    int closest_below, closest_above;
    int target_index = -1;

    find_closest_numbers(stack_b, element_to_move, &closest_below, &closest_above);

    if (closest_above == INT_MAX)
        target_index = stack_b->size;
    else 
    {
        target_index = 0;
        while (target_index < stack_b->size && stack_b->data[target_index] != closest_above)
            target_index++;
    }

    return target_index;
}


int calculate_r_both(int r_a, int r_b)
{
    int dual_rotation;

	if (r_a > 0 && r_b > 0)
    	dual_rotation = ft_min(r_a, r_b);
    else if (r_a < 0 && r_b < 0)
		dual_rotation = -(ft_min(ft_abs(r_a), ft_abs(r_b)));
    else
		dual_rotation = 0;
    return dual_rotation;
}

int	calculate_ops(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	r_a;
	int	r_b;
	int	r_both;
	int	target_index;
	int	ops;

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
	ops = ft_abs(r_a) + ft_abs(r_b) - ft_abs(r_both) + 1;
	return (ops);
}