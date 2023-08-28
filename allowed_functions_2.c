/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:56:50 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 16:25:23 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *stack)
{
	int	i;
	int	value;

	if (stack->size > 1)
	{
		value = stack->data[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->size - 1] = value;
		printf("rb\n");
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack *stack)
{
	int	value;
	int	i;

	if (stack->size > 1)
	{
		value = stack->data[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = value;
		printf("rra\n");
	}
}

void	rrb(t_stack *stack)
{
	int	value;
	int	i;

	if (stack->size > 1)
	{
		value = stack->data[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = value;
		printf("rrb\n");
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	printf("rrr\n");
}
