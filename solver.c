/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:07:09 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/29 16:21:25 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack_size_3(t_stack *stk)
{
	while (!(stk->data[0] < stk->data[1] && stk->data[1] < stk->data[2]))
	{
		if (stk->data[0] > stk->data[1] && stk->data[0] < stk->data[2])
			sa(stk);
		else if (stk->data[1] > stk->data[0] && stk->data[1] > stk->data[2])
			rra(stk);
		else if (stk->data[0] > stk->data[1] && stk->data[0] > stk->data[2])
			ra(stk);
	}
}

void	order_stack_size_4(t_stack *stk, t_stack *stk_b)
{
	int	min_index;

	while (!is_stack_ordered(stk))
	{
		min_index = ft_index_of_min(stk);
		if (min_index == 3)
		{
			pb(stk, stk_b);
			order_stack_size_3(stk);
			pa(stk, stk_b);
			return ;
		}
		else
		{
			if (min_index == 0)
				ra(stk);
			else if (min_index == 1)
				rra(stk);
			else if (min_index == 2)
				sa(stk);
		}
	}
}

void	order_stack_size_5(t_stack *stk, t_stack *stk_b)
{
	int	min_index;
	int	i;

	i = 0;
	while (i < 2) 
	{
		min_index = ft_index_of_min(stk);
		while (min_index != 0) 
		{
			if (min_index < 3)
				ra(stk);
			else
				rra(stk);
			min_index = ft_index_of_min(stk);
		}
		pb(stk, stk_b);
		++i;
	}
	order_stack_size_3(stk);
	pa(stk, stk_b);
	pa(stk, stk_b); 
}
/*
void	push_from_index(t_stack *stack_a, t_stack *stack_b, int index, int direction)
{
	int	r_a;
	int	r_b;
	int	r_both;
	int	target_index;

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
	if (direction == 0)
		pb(stack_a, stack_b);
	else
		pa(stack_a, stack_b);
}
*/
void rotate_to_target(t_stack *stack_a, t_stack *stack_b, int index, int target_index {
    int r_a;
    int r_b;
    int r_both;

    // ... the logic to calculate r_a, r_b, r_both remains the same ...

    perform_rotations_a(stack_a, (r_a - r_both));
    perform_rotations_b(stack_b, (r_b - r_both));
    perform_rotations_both(stack_a, stack_b, r_both);
}

void order_next_num_a_to_b(t_stack *stack_a, t_stack *stack_b, int index) {
    int target_index = calculate_target_index(stack_a, stack_b, index);
    rotate_to_target(stack_a, stack_b, index, target_index, 0);
    pb(stack_a, stack_b);
}

void order_next_num_b_to_a(t_stack *stack_a, t_stack *stack_b, int index) {
    int target_index = calculate_target_index(stack_a, stack_b, index);
    rotate_to_target(stack_a, stack_b, index, target_index, 1);
    pa(stack_a, stack_b);
}

void	order_next_num(t_stack *stack_a, t_stack *stack_b, int direction)
{
	int	min_index;
	int	min_ops;
	int	ops;
	int	i;

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
			break ;
		push_from_index(stack_a, stack_b, min_index, direction);
	}
}
