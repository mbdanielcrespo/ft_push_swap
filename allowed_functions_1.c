/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:56:50 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 16:25:45 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->data[0];
		stack->data[0] = stack->data[1];
		stack->data[1] = tmp;
		printf("sa\n");
	}
}

void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->data[0];
		stack->data[0] = stack->data[1];
		stack->data[1] = tmp;
		printf("sb\n");
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (stack_b->size > 0)
	{
		value = stack_b->data[0];
		shift_stack_up(stack_b);
		shift_stack_down(stack_a);
		stack_a->data[0] = value;
		printf("pa\n");
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (stack_a->size > 0)
	{
		value = stack_a->data[0];
		shift_stack_up(stack_a);
		shift_stack_down(stack_b);
		stack_b->data[0] = value;
		printf("pb\n");
	}
}

void	ra(t_stack *stack)
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
		printf("ra\n");
	}
}
