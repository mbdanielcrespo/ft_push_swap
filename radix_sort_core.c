#include "push_swap.h"

void	sort_by_num_position(t_stack *stack_a, t_stack *stack_b, int position)
{
	int	i;
	int digit;

	i = 0;
	digit = 0;
	while (digit <= 9)
	{
		while (i < stack_a->size)
		{
			if (digit_is_checked(stack_a, position, digit))
				break ; 
			if (get_num_at_pos(stack_a->data[0], position) == digit)
			{
				pb(stack_a, stack_b);
				i--;
			}
			else
				ra(stack_a);
			i++;
		}
		i = 0;
		digit++;;
	}
}

void	rev_sort_num_by_pos(t_stack *stack_a, t_stack *stack_b, int position)
{
	int	i;
	int digit;

	i = 0;
	digit = 9;
	while (digit >= 0)
	{
		//printf("digir -> %d\n", digit);
		while (i < stack_b->size)
		{
			if (digit_is_checked(stack_b, position, digit))
				break ;
			if (get_num_at_pos(stack_b->data[0], position) == digit)
			{
				//printf("num: %d, pos: %d, num_at_pos: %d\n", stack_b->data[0], position, get_num_at_pos(stack_b->data[0], position));
				pa(stack_a, stack_b);
				i--;
			}
			else
				rb(stack_b);
			i++;
		}
		i = 0;
		digit--;
	}
}

int	sort_negatives(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->data[0] < 0)
		{
			pb(stack_a, stack_b);
			i--;
		}
		else
			ra(stack_a);
		i++;
	}
}

int	merge_negatives(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->size;

	while (i > 0)
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
		i--;
	}
}