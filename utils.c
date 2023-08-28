/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:25:45 by danalmei          #+#    #+#             */
/*   Updated: 2023/08/28 13:55:33 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (b < a)
		return (b);
	else
		return (a);
}

int	ft_max(int a, int b)
{
	if (b > a)
		return (b);
	else
		return (a);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}

void	shift_stack_up(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->size--;
}

void	shift_stack_down(t_stack *stack)
{
	int	i;

	i = stack->size - 1;
	while (i >= 0)
	{
		stack->data[i + 1] = stack->data[i];
		i--;
	}
	stack->size++;
}
