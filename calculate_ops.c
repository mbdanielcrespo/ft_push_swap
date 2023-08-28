/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:06:59 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 16:54:36 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_of_min(t_stack *stk)
{
	int	min_val;
	int	min_index;
	int	i;

	min_val = stk->data[0];
	min_index = 0;
	i = 0;
	while (i < stk->size)
	{
		if (stk->data[i] < min_val)
		{
			min_val = stk->data[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	find_closest(t_stack *stack_b, int el_to_move, int *cl_blw, int *cl_abv)
{
	int	i;

	i = 0;
	*cl_blw = INT_MIN;
	*cl_abv = INT_MAX;
	while (i < stack_b->size) 
	{
		if (stack_b->data[i] < el_to_move && stack_b->data[i] > *cl_blw)
			*cl_blw = stack_b->data[i];
		else if (stack_b->data[i] > el_to_move && stack_b->data[i] < *cl_abv)
			*cl_abv = stack_b->data[i];
		i++;
	}
}

int	calculate_target_index(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	el_to_move;
	int	cl_blw; 
	int	cl_abv;
	int	t_index;

	t_index = -1;
	el_to_move = stack_a->data[index];
	find_closest(stack_b, el_to_move, &cl_blw, &cl_abv);
	if (cl_abv == INT_MAX)
		t_index = stack_b->size;
	else 
	{
		t_index = 0;
		while (t_index < stack_b->size && stack_b->data[t_index] != cl_abv)
			t_index++;
	}
	return (t_index);
}

int	calculate_r_both(int r_a, int r_b)
{
	int	dual_rotation;

	if (r_a > 0 && r_b > 0)
		dual_rotation = ft_min(r_a, r_b);
	else if (r_a < 0 && r_b < 0)
		dual_rotation = -(ft_min(ft_abs(r_a), ft_abs(r_b)));
	else
		dual_rotation = 0;
	return (dual_rotation);
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
