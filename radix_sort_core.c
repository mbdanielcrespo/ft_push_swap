/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:33:52 by danalmei          #+#    #+#             */
/*   Updated: 2023/09/09 18:44:18 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_num_position(t_stack *stack_a, t_stack *stack_b, int position)
{
	int	i;
	int	digit;

	i = 0;
	digit = 0;
	while (digit <= 9)
	{
		//printf("digits: %d\n", digit);
		while (!digit_is_checked(stack_a, position, digit))
		{
			if (get_num_at_pos(stack_a->data[0], position) == digit)
			{
				//printf("a>b num: %d  pos: %d, num_at_pos: %d\n", stack_a->data[0], position, get_num_at_pos(stack_a->data[0], position));
				pb(stack_a, stack_b);
				i--;
			}
			else
				ra(stack_a);
			i++;
		}
		//printf("Stack a size -> %d, i -> %d\n", stack_a->size, i);
		while (i < stack_a->size)
		{
			ra(stack_a);
			i++;
		}
		i = 0;
		digit++;
	}
}

int	digit_is_rev_checked(t_stack *stack, int pos, int digit)
{
	int	i;

	i = stack->size;
	while(i > 0)
	{
		if (get_num_at_pos(stack->data[i], pos) == digit)
			return (0);
		i--;
	}
	return (1);
}

void	rev_sort_num_by_pos(t_stack *stack_a, t_stack *stack_b, int position)
{
	int	i;
	int digit;

	i = 0;
	digit = 9;
	while (digit >= 0)
	{
		while (!digit_is_checked(stack_b, position, digit))
		{
			if (get_num_at_pos(stack_b->data[0], position) == digit)
			{
				pa(stack_a, stack_b);
				i--;
			}
			else
				rb(stack_b);
			i++;
		}
		//printf("Stack size -> %d, i -> %d\n", stack_b->size, i);
		while (i < stack_b->size)
		{
			rb(stack_b);
			i++;
		}
		//printf("Rotated to initial postion, current:\n");
		//print_stack("B", stack_b);
		i = 0;
		digit--;
	}
}

void	sort_negatives(t_stack *stack_a, t_stack *stack_b)
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

void	merge_negatives(t_stack *stack_a, t_stack *stack_b)
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
