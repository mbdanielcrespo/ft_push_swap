/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:26:17 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 16:26:33 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_rotations_a(t_stack *stack, int rotations)
{
	if (rotations >= 0)
	{
		while (rotations > 0)
		{
			ra(stack);
			rotations--;
		}
	}
	else
	{
		while (rotations < 0)
		{
			rra(stack);
			rotations++;
		}
	}
}

void	perform_rotations_b(t_stack *stack, int rotations)
{
	if (rotations >= 0)
	{
		while (rotations > 0)
		{
			rb(stack);
			rotations--;
		}
	}
	else
	{
		while (rotations < 0)
		{
			rrb(stack);
			rotations++;
		}
	}
}

void	perform_rotations_both(t_stack *stack_a, t_stack *stack_b, int rot)
{
	while (rot > 0)
	{
		rr(stack_a, stack_b);
		rot--;
	}
	while (rot < 0)
	{
		rrr(stack_a, stack_b);
		rot++;
	}
}
