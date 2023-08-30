#include "push_swap.h"

// Calc rotations to get index to the top
int calc_rot(t_stack stack, int index)
{
	int ops;
	int rot;
	int rev_rot;

	if (index >= (stack->size / 2))
		rot = index;
	else
		rev_rot = index - stack->size;
	return (ops);
}

int calc_rot_both(int rot_a, int rot_b)
{
	if (rot_a > 0 && rot_b > 0)
		return (ft_min(rot_a, rot_b));
	else if (rot_a < 0 && rot_b < 0)
		return (ft_max(rot_a, rot_b));
	else
		return (0);
}

int calc_ops_a_to_b(t_stack stack_a, t_stack stack_b, int index_a, int index_b)
{
	int rot_a;
	int rot_b;
	int rot_both;

	rot_a = calc_rot(stack_a, index_a);
	rot_b = calc_rot(stack_b, index_b);
	rot_both = calc_rot_both(rot_a, rot_b);
	if (rot_both != 0)
	{
		rot_a = rot_a - rot_both;
		rot_b = rot_b - rot_both;
	}
	ops = ft_abs(rot_a) + ft_abs(rot_b);
}

int	calc_t_index(t_stack t_stack, int num)
{
	int i;
	int	diff;
	int	min_diff;
	int	min_index;

	i = 0;
	min_diff = INT_MAX;
	min_index = -1;
	while(i < t_stack->size) // fix logic
	{
		diff = num - t_stack->data[i];
		if (ft_abs(diff) < ft_abs(min_diff) || (diff >= 0 && diff == -min_diff))
		{
            min_diff = diff;
            min_index = i;
        }
		i++;
	}
	if (min_index == -1)
		return (t_stack->size);
	else
		return (min_index);
}