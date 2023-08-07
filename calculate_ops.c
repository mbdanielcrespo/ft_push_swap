#include "push_swap.h"

int	calculate_target_index(t_stack *stack_a, t_stack *stack_b, int index)
{
	int element_to_move;
	int	current;
    int target_index;
	int	i;
	
	element_to_move = stack_a->data[index];
	target_index = -1;
	i = 0;
	while (i < stack_b->size)
	{
		current = stack_b->data[i];
		if (element_to_move < current)
        {
			target_index = i;
            break;
        }
        i++;
	}
	if (target_index == -1)
		target_index = stack_b->size;
    //printf("Target index  element_to_move: %d, ");
	return (target_index);
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
	int	min_ops;

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
	min_ops = ft_abs(r_a) + ft_abs(r_b) - ft_abs(r_both) + 1;
	printf("Calculate operations: value: %d, rotations_a: %d, target_index: %d, rotations_b: %d, rotations_both: %d, ops: %d\n", stack_a->data[index], r_a, target_index, r_b, r_both, min_ops);
	return (min_ops);
}