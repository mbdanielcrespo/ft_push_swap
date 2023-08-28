/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:26:01 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 16:14:32 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_break_point(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1) 
	{
		if (stack->data[i] > stack->data[i + 1]) 
			return (i);
		i++;
	}
	return (-1);
}

int	check_after_break(t_stack *stack, int break_point)
{
	int	i; 

	i = break_point + 1;
	while (i < stack->size - 1) 
	{
		if (stack->data[i] > stack->data[i + 1]) 
			return (0);
		i++;
	}
	return (1);
}

int	rotations_to_sort(t_stack *stack)
{
	int	rotations;
	int	break_point;

	break_point = find_break_point(stack);
	if (break_point == -1) 
		return (0);
	if (!check_after_break(stack, break_point)) 
		return (0);
	rotations = stack->size - (break_point + 1);
	if (rotations > stack->size / 2)
		return (rotations - stack->size);
	return (rotations);
}

int	is_circularly_sorted(t_stack *stack)
{
	int	break_point;

	break_point = find_break_point(stack);
	if (break_point == -1) 
		return (1);
	if (!check_after_break(stack, break_point)) 
		return (0);
	if (stack->data[0] < stack->data[stack->size - 1]) 
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	int	i; 
	int	j;

	i = 0;
	while (i < stack->size) 
	{
		j = i + 1;
		while (j < stack->size) 
		{
			if (stack->data[i] == stack->data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
